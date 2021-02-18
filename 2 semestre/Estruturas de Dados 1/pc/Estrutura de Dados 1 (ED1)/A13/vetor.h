#define VTAM_START 4 //ideal n�meros 2^x
typedef enum{false,true} Boolean;

////////////////////////////////
//TIPO DE DADOS
typedef int DataType;
typedef struct{
  DataType* vetor;
  int size;
  int length;
} Vetor;

////////////////////////////////
//OPERAÇÕES (PROTÓTIPOS)
Vetor* vetor_new();
void vetor_free(Vetor* v);
void vetor_print(char* nome, Vetor* v);
int vetor_size(Vetor* v);
Boolean vetor_add(Vetor* v, DataType element);
Boolean vetor_set(Vetor* v, int index, DataType valor);
DataType vetor_get1(Vetor* v, int index);
Boolean vetor_get2(Vetor* v, int index, DataType *ptr);
DataType* vetor_get3(Vetor* v, int index);
Boolean vetor_insert(Vetor* v, DataType element, int index);
DataType vetor_remove1(Vetor* v, int index);
Boolean vetor_remove2(Vetor* v, int index, DataType* ptr);
DataType vetor_shift1(Vetor* v);
Boolean vetor_shift2(Vetor* v, DataType* ptr);
void vetor_map(Vetor* v, void (*funcao)(DataType*));
Vetor* vetor_sub1(Vetor* v, int index);
Vetor* vetor_sub2(Vetor* v, int start, int end);
Vetor* vetor_filter(Vetor* v, Boolean (*funcao)(DataType*));
void vetor_sort(Vetor* v);
void vetor_genericSort(Vetor* v, int (*pfuncao)(DataType* a, DataType* b));

int vetor_import(Vetor* v, char* nomeArquivo);
Vetor* vetor_load(char* nomeArquivo);
int vetor_save(Vetor* v, char* nomeArquivo);

////////////////////////////////
//OPERAÇÕES (PROTÓTIPOS INTERNOS)
void in_vetor_aumenta(Vetor* v);
void in_vetor_diminui(Vetor* v);

////////////////////////////////
//OPERAÇÕES (IMPLEMENTAÇÃO)
Vetor* vetor_new(){
  Vetor* v = (Vetor*)malloc(sizeof(Vetor));
  v->vetor = (DataType*)calloc(VTAM_START, sizeof(DataType));
  v->size = 0;
  v->length = VTAM_START;
  return v;
}

void vetor_free(Vetor* v){
  free(v->vetor);
  free(v);
}

int vetor_size(Vetor* v){
  return v->size;
}

void vetor_print(char* nome, Vetor* v){
  printf("%s = {", nome);
  for(int i=0; i<v->size; i++){
    if(i != 0) printf(", %d", v->vetor[i]);
    else printf("%d", v->vetor[i]);
  }
  printf("}\n");
}

Boolean vetor_add(Vetor* v, DataType element){
  in_vetor_aumenta(v);
  v->vetor[v->size] = element;
  v->size++;
  return true;
}

Boolean vetor_set(Vetor* v, int index, DataType valor){
  if(index >= v->size || index < 0) return false;
  v->vetor[index] = valor;
  return true;
}

DataType vetor_get1(Vetor* v, int index){
  if(index >= v->size || index < 0) return 0;
  return v->vetor[index];
}

Boolean vetor_get2(Vetor* v, int index, DataType *ptr){
  if(index >= v->size || index < 0) return false;
  *ptr = v->vetor[index];
  return true;
}

DataType* vetor_get3(Vetor* v, int index){
  if(index >= v->size || index < 0) return &v->vetor[0];
  return &v->vetor[index];
}

Boolean vetor_insert(Vetor* v, DataType element, int index){ //vetor, item que eu quero guardar, lugar onde guardar
  if(index > v->size || index < 0) return false;
  in_vetor_aumenta(v);
  ////
  DataType* tmp = (DataType*)calloc(v->length, sizeof(DataType));
  for(int i=0; i<v->length; i++){
    if(i < index) tmp[i] = v->vetor[i];
    else if(i == index) tmp[i] = element;
    else tmp[i] = v->vetor[i-1];
  }
  v->vetor = tmp;
  v->size++;
  return true;
}


DataType vetor_remove1(Vetor* v, int index){
  if(index > v->size || index < 0) return 0;
  DataType temp = v->vetor[index];
  ////
  DataType* tmp = (DataType*)calloc(v->length, sizeof(DataType));
  for(int i=0; i<v->length; i++){
    if(i < index) tmp[i] = v->vetor[i];
    else if(i+1 != v->length) tmp[i] = v->vetor[i+1];
    else tmp[i] = 0;
  }
  v->vetor = tmp;
  v->size--;
  ////
  in_vetor_diminui(v);
  return temp;
}

Boolean vetor_remove2(Vetor* v, int index, DataType* ptr){
  if(index > v->size || index < 0) return false;
  *ptr = v->vetor[index];
  ////
  DataType* tmp = (DataType*)calloc(v->length, sizeof(DataType));
  for(int i=0; i<v->length; i++){
    if(i < index) tmp[i] = v->vetor[i];
    else if(i+1 != v->length) tmp[i] = v->vetor[i+1];
    else tmp[i] = 0;
  }
  v->vetor = tmp;
  v->size--;
  ////
  in_vetor_diminui(v);
  return true;
}

DataType vetor_shift1(Vetor* v){
  DataType temp = v->vetor[0];
  ////
  DataType* tmp = (DataType*)calloc(v->length, sizeof(DataType));
  for(int i=0; i<v->length; i++){
    if(i+1 != v->length) tmp[i] = v->vetor[i+1];
    else tmp[i] = 0;
  }
  v->vetor = tmp;
  v->size--;
  ////
  in_vetor_diminui(v);
  return temp;
}


Boolean vetor_shift2(Vetor* v, DataType* ptr){
  *ptr = v->vetor[0];
  ////
  DataType* tmp = (DataType*)calloc(v->length, sizeof(DataType));
  for(int i=0; i<v->length; i++){
    if(i+1 != v->length) tmp[i] = v->vetor[i+1];
    else tmp[i] = 0;
  }
  v->vetor = tmp;
  v->size--;
  ////
  in_vetor_diminui(v);
  return true;
}

void vetor_map(Vetor* v, void (*funcao)(DataType*)){
  for(int i=0; i<v->size; i++){
    funcao(&v->vetor[i]);
  }
}

Vetor* vetor_sub1(Vetor* v, int index){
  if(index >= v->size || index <= v->size*(-1) ) return 0;
  Vetor* v2 = vetor_new();
  int idx = (index >= 0 ? index : v->size+index);
  ////
  for(int i=idx; i<v->size; i++){
    vetor_add(v2, v->vetor[i]);
  }
  return v2;
}

Vetor* vetor_sub2(Vetor* v, int start, int end){
  if(start >= v->size || start < 0 ) return 0;
  if(end > v->size || end < start) return 0;
  Vetor* v2 = vetor_new();
  ////
  for(int i=start; i < end; i++){
    vetor_add(v2, v->vetor[i]);
  }
  return v2;
}

Vetor* vetor_filter(Vetor* v, Boolean (*funcao)(DataType*)){
  Vetor* v2 = vetor_new();
  for(int i=0; i < v->size; i++){
    if(funcao(&v->vetor[i]) == true) vetor_add(v2, v->vetor[i]);
  }
  return v2;
}

void vetor_sort(Vetor* v){
  int i, fim;
  for(fim = v->size-1; fim>0; fim--){
    int houve_troca = 0;
    for(i=0; i<fim; i++){
      if(v->vetor[i]>v->vetor[i+1]){
        DataType temp = v->vetor[i];
        v->vetor[i] = v->vetor[i+1];
        v->vetor[i+1] = temp;
        houve_troca = 1;
      }
    }
    if(houve_troca == 0) return;
  }
}

void vetor_genericSort(Vetor* v, int (*funcao)(DataType* a, DataType* b) ){
  int i, fim;
  for(fim = v->size-1; fim>0; fim--){
    int houve_troca = 0;
    for(i=0; i<fim; i++){
      if(funcao(&v->vetor[i], &v->vetor[i+1]) == 1){
        DataType temp = v->vetor[i];
        v->vetor[i] = v->vetor[i+1];
        v->vetor[i+1] = temp;
        houve_troca = 1;
      }
    }
    if(houve_troca == 0) return;
  }
}


int vetor_save(Vetor* v, char* nomeArquivo){
  FILE *arq = fopen(nomeArquivo, "wb");
  if(arq == NULL) return 0;
  else{
    fwrite(v, sizeof(Vetor), 1, arq);
    fwrite(v->vetor, sizeof(DataType) * v->length, 1, arq);
    fclose(arq);
    return 1;
  }
}

Vetor* vetor_load(char* nomeArquivo){
  FILE *arq = fopen(nomeArquivo, "rb");
  if(arq == NULL) printf("erro");//return 0;
  else{
    Vetor *v;
    fread(v, sizeof(Vetor), 1, arq);
    v->vetor = malloc(sizeof(DataType) * v->length);
    fread(v->vetor, sizeof(DataType) * v->length, 1, arq);
    fclose(arq);
    return v;
  }
}

int vetor_import(Vetor* v, char* nomeArquivo){
  int qtde=0;
  FILE *arq;
  if((arq = fopen(nomeArquivo, "r")) == NULL) return 0;
  //
  do{
    char tmp[9] = "";
    int flag = 0;
    //
    while(!feof(arq)){
      char tmp2[2];
      tmp2[0] = getc(arq);
      tmp2[1] = '\0';
      //
      if(tmp2[0] != '0' && tmp2[0] != '1' && tmp2[0] != '2' && tmp2[0] != '3' && tmp2[0] != '4' && tmp2[0] != '5' && tmp2[0] != '6' && tmp2[0] != '7' && tmp2[0] != '8' && tmp2[0] != '9'){
        break;
      }else{
        flag++;
        strcat(tmp, tmp2);
      }
    }
    if(flag > 0){
      if(vetor_add(v, atoi(tmp)) == true) qtde++;
    }
  }while(!feof(arq));
  //
  fclose(arq);
  return qtde;
}

////////////////////////////////
//INTERNO
void in_vetor_aumenta(Vetor* v){
  if(v->size >= v->length){
    DataType* tmp = (DataType*)calloc(v->length*2, sizeof(DataType));
    for(int i=0; i<v->size; i++){
      tmp[i] = v->vetor[i];
    }
    v->vetor = tmp;
    v->length *= 2;
  }
}

void in_vetor_diminui(Vetor* v){
  float x = v->size * 100.0 / v->length;
  if(x <= 25 && v->length != 1){
    DataType* tmp = (DataType*)calloc(v->length/2, sizeof(DataType));
    for(int i=0; i<v->size; i++){
      tmp[i] = v->vetor[i];
    }
    v->vetor = tmp;
    v->length = v->length/2;
  }
}
