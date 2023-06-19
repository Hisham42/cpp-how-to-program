template <typename T>

T minimum(T x, T y){
    if (x > y)
    {
        return y;
    }
    else if (y > x)
    {
        return x;
    }
    else
        return 0;
    
    
}

