#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 20
struct PolyNode{
    double coef;
    int expo;
    PolyNode *next;
};

class Poly{
    private:
        PolyNode *head;
    public:
        Poly();
        void pcreate();
        void pr();
        void psort();
        void add(Poly LB);
        void mult(Poly &LB);
        void cp(Poly LB);
        void check();
};

Poly::Poly(){
	head = new PolyNode;
    head->next = NULL;
}

void Poly::pcreate(){
	int n;
	cin >> n;
    PolyNode *s;
    for(int i = 0;i < n;i++){
        s = new PolyNode;
        cin >> s->coef;
        cin >> s->expo;
        s->next = head->next;
        head->next = s;
    }
}

void Poly::pr(){
    PolyNode *p = head->next;
    int cnt = 0;
    double coef;
    while(p){
    	if(cnt++){
    		if(coef > 0) cout << "+";
    		else cout << "-";
    	}
    	if(fabs(fabs(p->coef)-1.0) > 1e-8 || !p->expo)
    		cout << fabs(p->coef);
        if(p->expo < 0)
            cout << "x^(" << p->expo << ")";
        else if(p->expo > 0)
            cout << "x^" << p->expo;
        p = p->next;
    }
    cout << endl;
}

void Poly::psort(){
    PolyNode *p = head->next, *q, *r;
    while(p){
        r = p;
        q = r->next;
        while(q){
            if(q->expo > r->expo){
            	swap(q->expo, r->expo);
            	swap(q->coef, r->coef);
            }
            q = q->next;
        }
        p = p->next;
    }
}

void Poly::add(Poly L){
    Poly LB; LB.cp(L);
    PolyNode *la = head, *lb = LB.head;
    PolyNode *a = head->next, *b = LB.head->next, *t;
    while(b && a){
        while(a && a->expo > b->expo){
            la = a;
            a = a->next;
        }
        if(!a) break;
        if(a->expo < b->expo){
            lb->next = b->next;
            b->next = a;
            la->next = b;
            la = b;
            b = lb->next;
        }
        else{
            a->coef += b->coef;
            lb = b;
            b = b->next;
        }
    }
    if(b)
        la->next = b;
}

void Poly::check(){
	PolyNode *la = head, *a = head->next, *t;
    while(a){
        if(!a->coef){
            t = a;
            la->next = a->next;
            a = la->next;
            delete t;
        }
        else{
            la = a;
            a = la->next;
        }
    }
}

void Poly::cp(Poly LB){
    PolyNode *p = head->next, *b = LB.head->next, *q;
    while(p){
        q = p->next;
        delete p;
        p = q;
    }
    p = head;
    while(b){
        q = new PolyNode;
        q->coef = b->coef;
        q->expo = b->expo;
        p->next = q;
        p = q;
        b = b->next;
    }
    p->next = NULL;
}

void Poly::mult(Poly &LB){
    PolyNode *a = head->next, *c;
    Poly LC, LD;
    while(a){
        LC.cp(LB);
        c = LC.head->next;
        while(c){
            c->coef *= a->coef;
            c->expo += a->expo;
            c = c->next;
        }
        LD.add(LC);
        LD.check();
        a = a->next;
    }
    LB.cp(LD);
}

int main(){
    Poly La, Lb;
    La.pcreate(); Lb.pcreate();
    La.check(); Lb.check();
    La.psort(); Lb.psort();
    cout << "After sorting\nLa = "; La.pr();
    cout << "After sorting\nLb = "; Lb.pr();
    La.mult(Lb);
    cout << "After multiply\nAns = "; Lb.pr();
    return 0;
}
