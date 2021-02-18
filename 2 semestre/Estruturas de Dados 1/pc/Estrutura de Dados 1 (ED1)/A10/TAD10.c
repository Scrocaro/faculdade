void shift(Pessoa** p, int tam, int x)
{
	for(int i=x; i<tam; i++)
	{
		p[i] = p[i+1];
	}
}

int agenda_consultaPorEstado(Agenda* agenda, char*  estado, Telefone* contatos)
{	
	int qtdcontatos = 0;
	for(int i=0; i < agenda->qtdePessoas; i++)
	{
		if(strcmp(agenda->pessoas[i]->endereco->estado, estado) == 0)
		{
			for(int x=0; x < agenda->pessoas[i]->qtdeContatos; x++)
			{
				strcpy(contatos[x].numero, agenda->pessoas[i]->telefones[x]->numero);
				strcpy(contatos[x].wpp, agenda->pessoas[i]->telefones[x]->wpp);
				qtdcontatos++;
			}
		}
	}return qtdcontatos;
}

void pessoa_cadastrarContato(Pessoa* p, char* numero, char* flagwpp)
{
	Telefone* contato = (Telefone*)malloc(sizeof(Telefone));
	strcpy(contato->numero, numero);
	strcpy(contato->wpp, flagwpp);
	p->telefones[p->qtdeContatos++] = contato;
}

void agenda_inserirPessoa(Agenda* agenda, Pessoa* p)
{
	if(agenda->qtdePessoas > agenda->tamVetor) return;
	agenda->pessoas[agenda->qtdePessoas++] = p;
}

void agenda_verificaReduzTamanho(Agenda* agenda)
{
	float  percent = (float)agenda->qtdePessoas/agenda->tamVetor;
	if(percent >= 0.25) return;
	Pessoa** new_p =  (Pessoa**)calloc(agenda->tamVetor/2, sizeof(Pessoa*));
	for(int i=0; i < agenda->qtdePessoas; i++)
	{
		new_p[i] = agenda->pessoas[i];
	}
	agenda->pessoas = new_p;
	agenda->tamVetor = agenda->tamVetor/2;
}

Pessoa* agenda_removerPessoa(Agenda*  agenda, char* email)
{
	int x;
	Pessoa* newp = pessoa_novo(agenda->pessoas[x]->nome, agenda->pessoas[x]->idade, agenda->pessoas[x]->email);
	pessoa_defineEndereco(newp, agenda->pessoas[x]->endereco->cep, agenda->pessoas[x]->numero, agenda->pessoas[x]->estado);
	for(int i=0; i < agenda->pessoas[x]->qtdeContatos; i++)
	{
		pessoa_cadastrarContato(newp, agenda->pessoas[x]->telefones[i]->numero, agenda->pessoas[x]->telefones[i]->wpp);
	}
	pessoa_desalocar(agenda->pessoas[x]);
	shift(agenda->pessoas, agenda->qtdePessoas, x);
	agenda_verificaReduzTamanho(agenda);
	agenda->qtdePessoas--;
	return newp;
}
