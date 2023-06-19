template <typename H>


H maximum(H x, H y){
    if (x > y)
    {
        return x;
    }
    else if (y > x)
    {
        return y;
    }
    else
        return 0;
    
}