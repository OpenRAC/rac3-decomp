#include "common.h"

/* localdecomp:start func_L01_0044C638 */
#include "vu0.h"

typedef int s128 __attribute__((mode(TI)));

extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_003C48A8(void *, void *);

s32 func_L01_0044C638(s32 a0, u8 *a1, s128 *a2, s128 *a3, s128 *a4, s128 *a5) {
    s128 m0[4];
    s128 m1[4];
    s128 m2[4];
    u8 *p = func_003C4D58(a1);
    if (p == 0) {
        *a4 = *a2;
        *a5 = *a3;
        return 0;
    }
    func_0038D328(m0, p);
    vec_add_ba(a4, a2, p + 16);
    vec_sub_ab(a4, a4, a1 + 16);
    if (*(s32 *)(p + 60) & 2) {
        func_0038D328(m2, p + 32);
        func_0038D5B0(m1, m2);
        func_0038D000(a4, a4, m1);
        func_0038D000(a4, a4, a1 + 192);
    } else {
        func_0038D000(a4, a4, m0);
    }
    vec_add_ba(a4, a4, a1 + 16);
    func_0038D328(m1, a3);
    func_0038D640(m1, m0, m1);
    func_003C48A8(m1, a5);
    return 1;
}
/* localdecomp:end func_L01_0044C638 */

/* localdecomp:start func_L01_0044C790 */

extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);

s32 func_L01_0044C790(s32 a0, u8 *a1, s128 *a2, s128 *a3) {
    s128 m0[4];
    s128 m1[4];
    s128 m2[4];
    u8 *p = func_003C4D58(a1);
    if (p == 0) {
        *a3 = *a2;
        return 0;
    }
    func_0038D328(m0, p);
    if (*(s32 *)(p + 60) & 2) {
        func_0038D328(m2, p + 32);
        func_0038D5B0(m1, m2);
        func_0038D000(a3, a2, m1);
        func_0038D000(a3, a3, a1 + 192);
    } else {
        func_0038D000(a3, a2, m0);
    }
    return 1;
}
/* localdecomp:end func_L01_0044C790 */

/* localdecomp:start func_L01_0044C870 */
#include "vu0.h"


extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);

s32 func_L01_0044C870(s32 a0, u8 *a1, s128 *a2, s128 *a3) {
    s128 m0[4];
    vu0_v4 v;
    s128 m1[4];
    s128 m2[4];
    vu0_v4 t;
    vu0_q qa, qb;
    u8 *p = func_003C4D58(a1);
    if (p == 0) {
        qzero(a3);
        return 0;
    }
    func_0038D328(m0, p);
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(p + 16)));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a2));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(a1 + 16)));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qa));
    vec_sub_ab(&v, &v, &t);
    if (*(s32 *)(p + 60) & 2) {
        func_0038D328(m2, p + 32);
        func_0038D5B0(m1, m2);
        func_0038D000(&v, &v, m1);
        func_0038D000(&v, &v, a1 + 192);
    } else {
        func_0038D000(&v, &v, m0);
    }
    vec_add_ba(&v, &v, a1 + 16);
    vec_sub_ba(a3, &v, a2);
    return 1;
}
/* localdecomp:end func_L01_0044C870 */

/* localdecomp:start func_L01_0044C998 */
#include "vu0.h"


extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D570(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_003C4BB0(void *, f32);
extern s32 func_L01_0044CB18_0044C998(s32 a0, u8 *a1, s128 *a2, s128 *a3, s128 *a4, s128 *a5);
extern u8 *D_001A71A0[];

s32 func_L01_0044C998(u8 *a0, u8 *a1, s128 *a2, s128 *a3, s128 *a4, s128 *a5) {
    s128 m0[4];
    s128 m1[4];
    s128 v;
    u8 *p = func_003C4D58(a1);
    if (p == 0) {
        return 0;
    }
    if (*(s32 *)(p + 60) & 0x40) {
        func_0038D328(m0, a1 + 240);
    } else {
        func_0038D570(m0, a1 + 192);
    }
    func_0038D000(a4, a2, m0);
    vec_add_ba(a4, a4, a1 + 16);
    func_0038D328(m1, a3);
    func_0038D640(m1, m0, m1);
    func_003C48A8(m1, a5);
    if (*(s32 *)(p + 60) & 4) {
        vec_add_ba(a4, a4, p + 16);
        func_L01_0044CB18_0044C998((s32)a0, a1, a4, a5, a2, a3);
        return 1;
    }
    if (a0 == D_001A71A0[0]) {
        return 1;
    }
    if (a0[0x22] < a1[0x22]) {
        v = *(s128 *)(p + 16);
        func_003C4BB0(&v, 1.0f);
        vec_add_ab(a4, a4, &v);
    }
    return 1;
}
/* localdecomp:end func_L01_0044C998 */

/* localdecomp:start func_L01_0044CB18 */
#include "vu0.h"


extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_003C48A8(void *, void *);

s32 func_L01_0044CB18(s32 a0, u8 *a1, s128 *a2, s128 *a3, s128 *a4, s128 *a5) {
    s128 m0[4];
    vu0_v4 v;
    s128 m1[4];
    u8 *p = func_003C4D58(a1);
    if (p == 0) {
        return 0;
    }
    if (*(s32 *)(p + 60) & 0x40) {
        func_0038D328(m0, a1 + 240);
        func_0038D5B0(m0, m0);
    } else {
        func_0038D5B0(m0, a1 + 192);
    }
    vec_sub_ab(&v, a2, a1 + 16);
    func_0038D028(a4, &v, m0);
    func_0038D328(m1, a3);
    func_0038D640(m1, m0, m1);
    func_003C48A8(m1, a5);
    return 1;
}
/* localdecomp:end func_L01_0044CB18 */
