
struct Seqpoly_Node{
	double coef;
	int expn;
};
struct Seqpoly{
	Seqpoly_Node *data;
	int length;
};
void init(Seqpoly *&T){
	T = new Seqpoly();
	T->data = new Seqpoly_Node[10086];
	T->length = 0;
}
void remove(Seqpoly *&T){
	delete T->data;
	delete T;
	T = 0;
}
void output(Seqpoly *T){
	for(int i = 0; i < T->length; i++){
		printf("%f*x^%d%c",T->data[i].coef,T->data[i].expn,(i==T->length-1)?('\n'):'+');	
	}
}
void insert(Seqpoly *&T, double coef, int expn){
	if(T->length == 10085)
		return;
	for(int i = 0; i < T->length; i++){
		if(T->data[i].expn > expn){
			for(int j = T->length; j>i; j--){
				T->data[j].coef=T->data[j-1].coef;
				T->data[j].expn=T->data[j-1].expn;
			}
			T->data[i].coef=coef;
			T->data[i].expn=expn;
			T->length++;
			return;
		}
		if(T->data[i].expn == expn){
			if(T->data[i].coef+coef != 0){
				T->data[i].coef = T->data[i].coef + coef;
			}
			else{
				T->length--;
				for(int j = i; i < T->length; i++){
					T->data[j].coef=T->data[j+1].coef;
					T->data[j].expn=T->data[j+1].expn;
				}
			}
			return;
		}
	}
	T->data[T->length].coef=coef;
	T->data[T->length].expn=expn;
	T->length++;
}
void erase(Seqpoly *&T,int expn){
	for(int i = 0; i < T->length; i++){
		if(T->data[i].expn == expn){
			for(int j = i; i < T->length; i++){
				T->data[j].coef=T->data[j+1].coef;
				T->data[j].expn=T->data[j+1].expn;
			}
			T->length--;
			return;
		}
	}
}
double value(Seqpoly *&T,double x){
	double ret = 0;
	for(int i = 0; i < T->length; i++){
		ret = ret + T->data[i].coef * pow(x,T->data[i].expn);
	}
	return ret;
}
