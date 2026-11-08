#include "common.h"

/* localdecomp:start func_L39_005F4690 */
__asm__(".extern D_L39_0024C9CC, 16");
__asm__(".extern D_L39_002402F4, 16");
__asm__(".extern D_L39_002402F0, 16");
__asm__(".extern D_L39_0024CAD0, 16");
__asm__(".extern D_L39_0024CAD0_b, 4");
extern unsigned char *D_L39_0024CAD0;
extern unsigned char *D_L39_0024CAD0_b;
extern unsigned char *D_L39_0024C9CC;
extern int D_L39_002402F4;
extern int D_L39_002402F0;
extern char D_L39_0024DE00[];
extern int D_L39_002BA040[];
extern void func_001264E0(int);
extern void func_L39_00590C70(float *);
extern void func_L39_00590508(float *, void *, float);
extern void func_L39_00591050(float *, void *, float *);
extern void func_L39_005FCFB8(int, void *, int);
extern void func_L39_005F4768(void);
extern void func_L39_005F44E0(void);
extern unsigned int func_L39_00590458(void *, unsigned int, unsigned int);

/* from rac2-decomp's func_002EF3B0 */
void func_L39_005F4690(void) {
    float m[16];
    unsigned char *p = D_L39_0024CAD0;
    D_L39_002402F0 = D_L39_002402F4;
    D_L39_0024C9CC = p;
    p += 0x10;
    D_L39_0024CAD0_b = p;
    func_L39_00590C70(m);
    func_L39_00590508(m + 12, D_L39_0024DE00, -1024.0f);
    m[15] = 1.0f;
    func_L39_00591050(m, D_L39_0024DE00 - 0x100, m);
    func_L39_005FCFB8(5, m, 4);
    func_L39_005FCFB8(0x14D, m, 4);
    func_001264E0(0);
    func_L39_005F4768();
    func_L39_005F44E0();
    func_L39_00590458(D_L39_002BA040, 0x3000, 0x40);
}
/* localdecomp:end func_L39_005F4690 */
