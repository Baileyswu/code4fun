int delta(double x){
    return fabs(x) < eps ? 0 : (x > 0 ? 1 : -1);
}
struct pt
{
    double x, y;
    pt(){}
    pt(double x, double y): x(x), y(y){}
    void sc(){
        scanf("%lf%lf", &x, &y);
    }
    bool eq(pt a){
        return !delta(x-a.x) && !delta(y-a.y);
    }
    double operator * (const pt &b){
        return x*b.y-y*b.x;
    }
    pt operator - (const pt &b){
        return pt(x-b.x, y-b.y);
    }
}p[N], q[N*N];
struct seg
{
    pt a, b;
    seg(){}
    seg(pt a, pt b) : a(a), b(b){}
    int jo(seg C, pt &ans){
        pt c = C.a, d = C.b;
        if(max(a.x,b.x) < min(c.x,d.x)||
            max(a.y,b.y) < min(c.y,d.y)||
            max(c.x,d.x) < min(a.x,b.x)||
            max(c.y,d.y) < min(a.y,b.y))
            return 0;
        int x = delta((b-a)*(c-a)), y = delta((b-a)*(d-a));
        if(x == 0 && y == 0) return -1;
        if(x == 0) ans = c;
        else if(y == 0) ans = d;
        else{
            ans.x =-(c*d*(a.x-b.x)-a*b*(c.x-d.x))/((a-b)*(c-d));
            ans.y =(a*b*(c.y-d.y)-c*d*(a.y-b.y))/((a-b)*(c-d));
        }
        if(delta(ans.x-max(a.x,b.x)) > 0 || delta(ans.x-min(a.x,b.x))<0)
            return 0;
        return 1;
    }
}s[N];
