#pragma once

class Niederreiter
{
public:
    Niederreiter();
    ~Niederreiter();

    void Next(int dim_num, int *seed, double quasi[]);
    double *All(int dim_num, int n, int *seed);

private:
    static const int MAXDEG = 50;
    static const int DIM_MAX = 20;
    static const int NBITS = 31;
    static constexpr double RECIP = 1.0 / (double)(1 << NBITS);

    void calcc(int dimen, int cj[DIM_MAX][NBITS]);

    void calcv(int maxv, int px_deg, int px[MAXDEG + 1], int add[2][2],
               int mul[2][2], int sub[2][2], int *b_deg, int b[MAXDEG + 1],
               int v[]);

    void plymul(int add[2][2], int mul[2][2], int pa_deg,
                int pa[MAXDEG + 1], int pb_deg, int pb[MAXDEG + 1],
                int *pc_deg, int pc[MAXDEG + 1]);

    void setfld(int add[2][2], int mul[2][2], int sub[2][2]);
};
