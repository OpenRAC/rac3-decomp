#include "common.h"

/* localdecomp:start func_L01_00436568 */
void func_L01_00436568(void) {

}
/* localdecomp:end func_L01_00436568 */

/* localdecomp:start func_L01_00436570 */
extern char *D_L01_001D67C8;
extern void func_L01_004D23E8(char *);

void func_L01_00436570(void) {
    char *v = D_L01_001D67C8;
    if (v != 0) {
        func_L01_004D23E8(v + 0x1FCA8);
    }
}
/* localdecomp:end func_L01_00436570 */

/* localdecomp:start func_L01_004365A0 */
extern char *D_L01_001D67C8;
extern void func_L01_004D24C0(char *);

void func_L01_004365A0(void) {
    char *v = D_L01_001D67C8;
    if (v != 0) {
        func_L01_004D24C0(v + 0x1FCA8);
    }
}
/* localdecomp:end func_L01_004365A0 */

/* localdecomp:start func_L01_004365D0 */
void func_L01_004365D0(void) {

}
/* localdecomp:end func_L01_004365D0 */

/* localdecomp:start func_L01_004365D8 */
extern char *D_L01_001D67C8;
extern void func_L01_004CE670(u8 *, s32, s32, s32, s32);

void func_L01_004365D8(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 *p = (*(u8 * *)&D_L01_001D67C8);
    if (p != 0) {
        func_L01_004CE670(&p[0x1FCA8], a3, a0, a1, a2);
    }
}
/* localdecomp:end func_L01_004365D8 */

/* localdecomp:start func_L01_00436620 */
extern char *D_L01_001D67C8;
extern s32 func_L01_004CE720(u8 *, s32);

s32 func_L01_00436620(s32 a0) {
    u8 *p = (*(u8 * *)&D_L01_001D67C8);
    if (p != 0) {
        return func_L01_004CE720(p + 0x1FCA8, a0);
    }
    return 0;
}
/* localdecomp:end func_L01_00436620 */

/* localdecomp:start func_L01_00436660 */
extern char *D_L01_001D67C8;
typedef struct {
    u8 pad[0x1FCA8];
    u8 sub[4];
} Unk00433628;

extern void func_L01_004CE758(void *, s32, s32, s32);

void func_L01_00436660(s32 a0, s32 a1, s32 a2) {
    if ((*(Unk00433628 * *)&D_L01_001D67C8) != 0) {
        func_L01_004CE758((*(Unk00433628 * *)&D_L01_001D67C8)->sub, a2, a0, a1);
    }
}
/* localdecomp:end func_L01_00436660 */

/* localdecomp:start func_L01_004366A0 */
extern char *D_L01_001D67C8;
extern void func_L01_004CDEA8(u8 *, s32, s32);

void func_L01_004366A0(s32 a0, s32 a1) {
    u8 *p = (*(u8 * *)&D_L01_001D67C8);
    if (p != 0) {
        func_L01_004CDEA8(p + 0x1FCA8, a0, a1);
    }
}
/* localdecomp:end func_L01_004366A0 */

/* localdecomp:start func_L01_004366E0 */
extern char *D_L01_001D67C8;
extern void func_L01_004CDF10(char *);

void func_L01_004366E0(void) {
    char *v = D_L01_001D67C8;
    if (v != 0) {
        func_L01_004CDF10(v + 0x1FCA8);
    }
}
/* localdecomp:end func_L01_004366E0 */

/* localdecomp:start func_L01_00436710 */
void func_L01_00436710(void) {

}
/* localdecomp:end func_L01_00436710 */

/* localdecomp:start func_L01_00436718 */
extern int D_00143950[];
extern void func_003AAE60(int);

void func_L01_00436718(int a0)
{
    func_003AAE60(D_00143950[0] != 0);
}
/* localdecomp:end func_L01_00436718 */

/* localdecomp:start func_L01_00436740 */
extern char D_L01_001EA940[];
extern char *D_L01_001D67C8;
extern int D_001CD0C0[];
extern int D_001D545C;
extern int D_00143950[];
extern void *func_0011A264(void *, int, int);
extern void func_L01_00436718(int a0);
extern int *func_L01_00521C90(int, int);
extern char *func_003AF0B8(int *, int);
extern void func_L01_00436568_00436740(void);
extern void func_L01_004365A0(void);
extern void func_L01_00436570(void);
extern void func_L01_00436710_00436740(void);
typedef struct {
    char pad[0x4DCC];
    void *cb1;
    void *cb2;
} SubBf_00436740;

void func_L01_00436740(void)
{
    char *state = D_L01_001EA940;
    char *obj;
    func_0011A264(*(void **)(state + 0x84), 0xCD, 0x40000);
    D_001CD0C0[104] = 0;
    D_001CD0C0[105] = 0;
    D_001CD0C0[106] = 0;
    D_001CD0C0[107] = 0;
    D_001CD0C0[108] = 0;
    D_001CD0C0[109] = 0;
    D_001CD0C0[110] = 0;
    D_001CD0C0[111] = 0;
    D_001CD0C0[112] = 0;
    D_001CD0C0[113] = 0;
    D_001CD0C0[114] = 0;
    D_001CD0C0[115] = 0;
    func_L01_00436718(D_00143950[0]);
    obj = func_003AF0B8(func_L01_00521C90(0x24F10, *(int *)(state + 0x84)), 0x40000);
    D_L01_001D67C8 = obj;
    if (D_001D545C == 0x1F5) {
        ((SubBf_00436740 *)(obj + 0x20000))->cb1 = func_L01_00436568_00436740;
        ((SubBf_00436740 *)(obj + 0x20000))->cb2 = func_L01_00436710_00436740;
    } else {
        ((SubBf_00436740 *)(obj + 0x20000))->cb1 = func_L01_004365A0;
        ((SubBf_00436740 *)(obj + 0x20000))->cb2 = func_L01_00436570;
    }
}
/* localdecomp:end func_L01_00436740 */
