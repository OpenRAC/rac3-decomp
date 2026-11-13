/* near miss (level 29: 35 diff, array destructor loop) */
#include "common.h"

/* localdecomp:start func_L29_0051FFB0 */
typedef struct {
    char _p0[0x50];
    void *arr[35];
    char _pDC[0x41DC - 0xDC];
} O_51FFB0;

extern O_51FFB0 D_L29_00258B80[];
extern O_51FFB0 D_L29_0026D4CC[];
extern void func_L29_00521900(void *);

void func_L29_0051FFB0(void) {
    O_51FFB0 *start = D_L29_00258B80;
    O_51FFB0 *p;
    void **q;
    void **lim;

    if (start != 0) {
        p = D_L29_0026D4CC;
        if (p != start) {
            do {
                lim = &p[-1].arr[0];
                p--;
                if (lim != 0) {
                    q = &p->arr[35];
                    if (lim != q) {
                        do {
                            q--;
                            if (*q != 0) {
                                func_L29_00521900(*q);
                            }
                            *q = 0;
                        } while (lim != q);
                    }
                }
            } while (p != start);
        }
    }
}
/* localdecomp:end func_L29_0051FFB0 */
