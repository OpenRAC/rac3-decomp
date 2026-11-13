/* near miss (level 3, Starship Phoenix): 3 differences: retail emits `sw $zero,0x10($sp)` (cnt = 0) after `sd $s1` and `lw $s1,0x68($s0)`, the C emits it first; this version builds in L03_0032FBA8.c (void * parameter, the file's func_L01_00516FD8(s32, void *) and K&R func_0011B2E8() prototypes); counter init order, an initialiser, a comma expression, the id init, the pointer source, the declaration order and a typed or untyped parameter all give the same 3 */
#include "common.h"

/* localdecomp:start func_L03_00330140 */
typedef struct S_00330140 { u8 pad00[0xFF]; u8 fFF; } S_00330140;
typedef struct T_00330140 { u8 pad00[0x68]; S_00330140 *p; } T_00330140;
extern u8 D_L03_002AE4D0[];
extern int D_L03_001DD148[];
__asm__(".extern D_L03_001DD148, 16");
extern int D_L03_001E11F0;
extern int D_L03_001E11F8;
extern void func_L03_00330438_00330140(void *, int, void *, int);
extern int func_00381FF0(int);
extern void func_L01_00516FD8(int, void *);
extern void func_L01_00517190(int, int);
extern void func_L01_00516AA0(int, int, int);
extern int func_L03_0032FA50(int);
extern int func_L03_0032F948(int);
extern void func_L03_0032FA78_00330140(int, int *, int *);
extern void func_0011B2E8();
void func_L03_00330140(void *arg) {
    T_00330140 *a = arg;
    S_00330140 *s = a->p;
    int cnt;
    int v[3];
    int *p;
    int i, id;
    cnt = 0;
    func_L03_00330438_00330140(a, ((s16 *)s)[0x110 / 2], &cnt, 0x8066CCFF);
    func_L03_00330438_00330140(a, ((s16 *)s)[0x10E / 2], &cnt, 0x80808080);
    {
        u8 *e = D_L03_002AE4D0 + s->fFF * 0x28;
        func_L01_00516FD8(0x47000F, (void *)func_00381FF0(*(int *)(e + 0x20)));
        func_L01_00516FD8(0x470012, (void *)func_00381FF0(*(int *)(e + 0x24)));
    }
    func_L01_00516FD8(0x470019, (void *)func_00381FF0(0xC45));
    func_0011B2E8(&D_L03_001E11F0, D_L03_001DD148, func_L03_0032FA50(s->fFF));
    func_0011B2E8(&D_L03_001E11F8, D_L03_001DD148, func_L03_0032F948(s->fFF));
    func_L01_00517190(0x47001C, s->fFF + 1);
    func_L03_0032FA78_00330140(s->fFF, p = &v[1], &v[2]);
    id = 0x470015;
    for (i = 1; i >= 0; i--, p++) {
        if (*p == 0) {
            func_L01_00516AA0(id, 1, 0);
        } else {
            func_L01_00516AA0(id, 1, 1);
            func_L01_00517190(id, *p);
        }
        id++;
    }
}
/* localdecomp:end func_L03_00330140 */
