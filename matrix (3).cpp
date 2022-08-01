#include <bits/stdc++.h>

using namespace std;
class matrix
{

private:
    int s;
    long long **m;

public:
    matrix(int);
    matrix(int, int);
    ~matrix();
    int size() const { return s; }
    long long& operator()(int, int) const;
    matrix operator+(const matrix &) const;
    matrix operator+(int) const;
    matrix operator*(const matrix &) const;
    matrix operator*(int) const;
    matrix& operator=(const matrix&);
    matrix& operator=(vector<vector<long long>>&);
    matrix& add(const matrix&);
    matrix& add(int);
    matrix& mult(const matrix&);
    matrix& mult(int);
    matrix& exp(int);
    matrix& trace(long long);
    matrix& fill(long long);
    matrix& add_trace(int);
    matrix& set(vector<vector<long long>>&);

    long long trace() const;
    void show() const;
    long long sum() const;
};

matrix::matrix(int s_)
{
    this->s = s_;
    this->m = (long long **)malloc(sizeof(long long) * this->s);
    for (int i = 0; i < this->s; ++i)
        this->m[i] = (long long *)calloc(sizeof(long long), this->s);
}

matrix::matrix(int s_, int n)
{
    this->s = s_;
    this->m = (long long **)malloc(sizeof(long long) * this->s);
    for (int i = 0; i < this->s; ++i)
    {
        this->m[i] = (long long *)calloc(sizeof(long long), this->s);
        for(int j = 0; j < this->s; ++j){
            this->m[i][j] = n + !n*(i==j);
        }
    }
}

matrix::~matrix()
{
    for (int i = 0; i < this->s; ++i)
    {
        free(this->m[i]);
    }
    free(this->m);
}

void matrix::show() const{
    for (int i = 0; i < this->size(); ++i)
    {
        for (int j = 0; j < this->size(); ++j)
        {
            cout << this->m[i][j] << " ";
        }
        cout << endl;
    }
}

matrix matrix::operator+(const matrix& o) const
{
    matrix ans(this->s);
    for (int i = 0; i < this->s; ++i)
    {
        for (int j = 0; j < this->s; ++j)
        {
            ans = this->m[i][j] + o(i, j);
        }
    }
    return ans;
}

matrix matrix::operator+(int b) const
{
    matrix ans(this -> s);
    for (int i = 0; i < this->s; ++i)
    {
        for (int j = 0; j < this->s; ++j)
        {
            ans = m[i][j] + b;
        }
    }
    return ans;
}

matrix matrix::operator*(const matrix & o) const
{
    matrix ans(this->s);
    for (int i = 0; i < this->s; ++i)
    {
        for (int j = 0; j < this->s; ++j)
        {
            for (int k = 0; k < this->s; ++k)
            {
                ans(i, k) += this->m[i][j] * o(j, k);
            }
        }
    }
    return ans;
}

matrix matrix::operator*(int b) const
{
    matrix ans(this ->s);
    for (int i = 0; i < this->s; ++i)
    {
        for (int j = 0; j < this->s; ++j)
        {
            ans = this->m[i][j]*b;
        }
    }
    return ans;
}

matrix& matrix::operator=(const matrix &o) 
{
    for (int i = 0; i < this->s; ++i)
    {
        for (int j = 0; j < this->s; ++j)
        {
            this->m[i][j] = o(i, j);
        }
    }
    return (*this);
}

matrix& matrix::operator=(vector<vector<long long>>& arr){
    for(int i = 0 ;i < this->s; ++i){
        for(int j = 0; j < this->s ; ++j){
            this->m[i][j] = arr[i][j];
        }
    }
    return (*this);
}

matrix& matrix::set(vector<vector<long long>>& arr){
    for(int i = 0 ;i < this->s; ++i){
        for(int j = 0; j < this->s ; ++j){
            this->m[i][j] = arr[i][j];
        }
    }
    return (*this);
}

matrix& matrix::add(const matrix& o)
{
    for (int i = 0; i < this->s; ++i)
    {
        for (int j = 0; j < this->s; ++j)
        {
            this->m[i][j] += o(i, j);
        }
    }
    return (*this);
}

matrix& matrix::add(int b)
{
    for (int i = 0; i < this->s; ++i)
    {
        for (int j = 0; j < this->s; ++j)
        {
            this->m[i][j] += b;
        }
    }
    return (*this);
}

matrix& matrix ::mult(const matrix& o)
{
    matrix ans(this->s);
    for (int i = 0; i < this->s; ++i)
    {
        for (int j = 0; j < this->s; ++j)
        {
            for (int k = 0; k < this->s; ++k)
            {
                ans(i, k) += this->m[i][j] * o(j, k);
            }
        }
    }
    this->operator=(ans);
    return *this;
}

matrix& matrix ::mult(int b)
{
    for (int i = 0; i < this->s; ++i)
    {
        for (int j = 0; j < this->s; ++j)
        {
            this->m[i][j] *= b;
        }
    }
    return (*this);
}

matrix& matrix ::exp(int e)
{
    matrix exponente (this->s);
    exponente = (*this);
    while (--e)
    {
        this->mult(exponente);
    }
    return (*this);
}

long long &matrix::operator()(int i, int j) const
{
    return this->m[i][j];
}

long long matrix::sum() const
{
    long long ans = 0;
    for (int i = 0; i < this->s; ++i)
    {
        for (int j = 0; j < this->s; ++j)
        {
            ans += this->m[i][j];
        }
    }
    return ans;
}

long long matrix::trace() const
{
    long long ans = 0;
    for (int i = 0; i < s; ++i)
        ans += m[i][i];
    return ans;
}

matrix& matrix::trace(long long b){
    for(int i = 0 ; i < this->s; ++i){
        this->m[i][i]=b;
    }
    return (*this);
}

matrix& matrix::add_trace(int b){
    for(int i = 0; i < this-> s; ++i){
        this->m[i][i] += b;
    }
    return (*this);
}

matrix& matrix::fill(long long b){
    for(int i = 0; i < this->s; ++i){
        for(int j = 0; j < this->s; ++j){
            this->m[i][j]=b;
        }
    }
    return (*this);
}


int main()
{
    matrix a(2);
    vector<vector<long long>> arr_a = {{1, 1},{1,0}};
    a.set(arr_a);
    
    a.exp(4).show();

    return 0;
}