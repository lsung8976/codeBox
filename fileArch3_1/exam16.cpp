#include <stdio.h>
#define MAX_TERMS 80

struct Term{
    int expon;
    float coeff;
};

class SparsePoly {
    int nTerms;
    Term term[MAX_TERMS];
public:
    SparsePoly(int n = 0 , Term *tm = NULL)
    : nTerms(n)
    {
        for(int i = 0 ;i < nTerms ; i++)
        {
            term[i].expon = tm[i].expon;
            term[i].coeff = tm[i].coeff;
        }
    }

    void read() {
        nTerms = 0;
        while (1) {
            printf("계수 차수 입력(종료 : -1): ");
            scanf("%f%d", &(term[nTerms].coeff), &(term[nTerms].expon));
            if(term[nTerms].expon < 0)
            {
                display("입력 다항식:");
                return;
            }
            nTerms++;
        }
    }

    void add(SparsePoly &a, SparsePoly &b) {
        for(int i = 0 ;i < a.getnTerms(); i++)
        {
            term[i].expon = a.term[i].expon;
            term[i].coeff = a.term[i].coeff;
        }
        nTerms = a.getnTerms();

        for(int i = 0 ;i < b.getnTerms(); i++)
        {
            term[nTerms + i].expon = b.term[i].expon;
            term[nTerms + i].coeff = b.term[i].coeff;
        }
        nTerms += b.getnTerms();

        for(int i = 0 ;i < nTerms; i++)
        {
            for(int j = i + 1 ;j < nTerms; j++)
            {
                if(term[i].expon == term[j].expon)
                {
                    term[i].coeff += term[j].coeff;
                    term[j].coeff = 0;
                }
            }
        }
    }

    void display(char *str = "SPoly"){
        int i;
        printf("\t%s", str);
        for(i = 0;i < nTerms; i++)
        {
            printf("%5.1f", term[i].coeff);
            if(term[i].expon > 0)
                printf(" x^%d + ", term[i].expon);
        }
        printf("\n");
    }

    int getnTerms()
    {
        return nTerms;
    }

    void setnTerms(int n)
    {
        nTerms = n;
    }
};

int main()
{
    SparsePoly a, b, c;
    a.read();
    b.read();
    c.add(a, b);

    a.display(" A = ");
    b.display(" B = ");
    c.display(" A + B = ");

    return 0;
}