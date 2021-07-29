#include <iostream>
using namespace std;
//8)(2*c - d/3)/(1 - a/4);
int main()
{
    int error;
    double res_asm;
    double a, d, c;
    cout << "Please, enter a:\n";
    cin >> a;
    cout << "Please, enter d:\n";
    cin >> d;
    cout << "Please, enter c:\n";
    cin >> c;

    cout << " (2*c - d/3)/(1 - a/4) " << endl;
   
    if ((1 - a / 4) == 0) {
        cout << "Do not try to divide by zero\n";
        return 0;
    }
    cout << " Result in integers (C++):" << (2 * c - d / 3) / (1 - a / 4) << endl;

   
    const double
        c2 = 2,
        c3 =  3,
        c4 = 4;
    const double c1 = 1;

    __asm {
        finit
        fld qword ptr[c]; st(0) = c
        fmul qword ptr[c2]; c * 2
        fld	qword ptr[d]; st(0) = d

        fdiv qword ptr[c3]; d / 3 * /
        fsubp st(1), st(0); 2 * c - d / 3


        fld qword ptr[c1]; 1

        fld qword ptr[a]; a
        fdiv qword ptr[c4]; a / 4


        fsubp st(1), st(0);1 - a / 4

        ftst; сравнение с нулем
        fstsw ax;записываем в АХ
        sahf;записываем в flags
        jz error_0

        fdivp	st(1), st
            jmp END
      

            error_0:
        mov error, 1
    
            END:
            fstp res_asm
    }

    if (error == 1)
        cout << "Division by zero!\n";
    else
    cout << "Result in integers (asm): " << res_asm << endl;
    return 0;


}