struct Linkpoly_Node{
	double base;
	int ex;
	Linkpoly_Node *next;
	Linkpoly_Node(double _base = 0, int _ex = 0, Linkpoly_Node* _next = NULL):base(_base),ex(_ex),next(_next){}
};
class Linkpoly{
	public:
		Linkpoly(){
			head = new Linkpoly_Node();
		}
	public:
		~Linkpoly(){
			Linkpoly_Node *p = head;
			while(p){
				Linkpoly_Node * del = p;
				p = p->next;
				delete del;
			}
		}
	public:
		void Output(){
			for(Linkpoly_Node *p = head->next; p; p = p->next){
				printf("%f*x^%d%c",p->base,p->ex,(p->next)?'+':'\n');
			}
		}
	public:
		void Input(double b, int e){
			Linkpoly_Node *p = head;
			while(true){
				if(p->next==NULL || p->next->ex>e){
					Linkpoly_Node *add;
					add = new Linkpoly_Node(b,e);
					add->next = p->next;
					p->next = add;
					break;
				}
				if(p->next->ex==e){
					if(p->next->base+b!=0){
						p->next->base = p->next->base + b;
					}
					else{
						Linkpoly_Node *del = p->next;
						p->next = p ->next->next;
						delete del;
					}
					break;
				}
				p = p -> next;
			}
		
		}
	public:
		void Delete(int e){
			Linkpoly_Node *p = head;
			while(p){
				if(p->next->ex==e){
					Linkpoly_Node *del = p->next;
					p->next = p->next->next;
					delete del;
					break;
				}
				p = p->next;
			}		
		}
	public:
		double Cal(double x){
			double ret = 0;
			Linkpoly_Node *p = head->next;
			while(p){
				ret = ret + mypow(x,p->ex) * p->base;
				p=p->next;
			}
			return ret;
		}
	private:
		double mypow(double base, int ex){
			if(ex==1)
				return base;
			double tmp = mypow(base,ex/2);
			if(ex&1)
				return base*tmp*tmp;
			else
				return tmp*tmp;
		}
	private:
		Linkpoly_Node * head;	
};
