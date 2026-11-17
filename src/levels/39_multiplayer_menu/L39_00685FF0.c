#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* localdecomp:start func_L39_00685FF0 */
typedef struct S_00685FF0 {
    u8 pad0[0x20];
    s32 f20;
} S_00685FF0;
typedef struct Vt_00685FF0 {
    u8 pad0[8];
    void (*f8)(void *, s32);
} Vt_00685FF0;
typedef struct O_00685FF0 {
    u8 pad0[0x60];
    Vt_00685FF0 *f60;
} O_00685FF0;

extern S_00685FF0 *D_L39_0024D760 __attribute__((section(".data")));
extern u8 D_L39_0024D764[];
extern u8 D_L39_0024D765[];
extern O_00685FF0 *D_001DC204_sda;
extern void func_L39_006D8938(void *);

O_00685FF0 *func_L39_00685FF0(void) {
    S_00685FF0 *p = D_L39_0024D760;
    O_00685FF0 *r;

    D_L39_0024D764[0] = 0;
    D_L39_0024D765[0] = 0;
    p->f20 = 0;
    func_L39_006D8938(p);
    D_001DC204_sda->f60->f8(D_001DC204_sda, 2);
    r = D_001DC204_sda;
    D_001DC204_sda = 0;
    return r;
}
/* localdecomp:end func_L39_00685FF0 */
