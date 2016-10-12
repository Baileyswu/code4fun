LL extend_Euclid(LL a, LL b, LL &x, LL &y){
    if(b==0){
        x = 1; y = 0;
        return a;
    }
    LL r = extend_Euclid(b, a%b, y, x);
    y -= a/b*x;
    return r;
}
LL equation(LL a, LL b, LL c, LL &x, LL &y)
{
    LL g = extend_Euclid(a, b, x, y);
    if(c % g) return -1;
    LL ran = b / g;
    x *= c/g;
    if(ran < 0) ran = -ran;
    x = (x%ran + ran) % ran;
    return 0;
}
