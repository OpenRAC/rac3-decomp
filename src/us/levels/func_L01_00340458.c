#include "common.h"

typedef int s128_00341C10 __attribute__((mode(TI)));
typedef union {
    s128_00341C10 q;
    f32 f[4];
} V_00341C10;
typedef struct {
    u8 a;
    u8 b;
    u8 pad[238];
} S_00341C10;
typedef struct {
    u8 pad0[16];
    u8 pos[20];
    s32 active;
    s32 visible;
    s32 target;
} Vars3462F0;
typedef struct {
    char pad0[0x20];
    unsigned char b32;
} Obj;
extern void fe_func_003C2880(Obj *);
typedef struct { u8 pad[0x1A]; s16 x1A; } V_347888;
typedef struct { u8 pad[0x68]; V_347888 *x68; } O_347888;

typedef struct {
    u8 pad0[0x170];
    f32 f170;
    u8 pad1[0x109C];
    s32 f1210;
    u8 pad2[0x13B0];
    s32 f25C4;
    u8 pad3[0x25];
    u8 b25ED;
    u8 pad4[0x2CE];
    s32 f28BC;
} G_00346998;

/* localdecomp:start func_L01_00340458 */
extern f32 D_L01_001DD1B8;
extern f32 D_L01_001DD1BC;
extern void func_L01_00441FB8(char *, s32, s32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_003407A0(char *);
extern void func_L01_003405B0(char *);
extern void func_L01_00340980(void);
extern void func_L01_00402498(void (*)(void), char *);
extern void func_L01_0044B598(char *, s32);

void func_L01_00340458(char *obj)
{
    char *sub = *(char **)(obj + 0x68);
    char **list;
    int count;
    float one;
    switch (*(unsigned char *)(obj + 0x20)) {
    case 0:
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        one = 1.0f;
        if (*(float *)(sub + 8) < one) {
            func_003BEBF8((float *)(sub + 8), one, D_L01_001DD1B8 * 0.0166666675f);
        } else {
            list = (char **)(sub + 0x10);
            if (!(*(float *)(sub + 12) < one))
                goto cleanup;
            if (*(int *)(sub + 4) == 0) {
                *(int *)(sub + 4) = 1;
                func_L01_003407A0(obj);
            }
            func_L01_003405B0(obj);
            func_003BEBF8((float *)(sub + 12), one, D_L01_001DD1BC * 0.0166666675f);
        }
        goto update;
    cleanup:
        count = 3;
        sub += 0x30;
        do {
            if (*list) {
                *(unsigned short *)(*list + 0x34) = *(unsigned short *)(sub - 0x10);
                func_L01_0044B598(*list, *(int *)sub);
            }
            sub += 4;
            count--;
            list++;
        } while (count >= 0);
        func_003BD360((Obj *)obj);
        break;
    update:
        func_L01_00402498(func_L01_00340980, obj);
        break;
    }
}
/* localdecomp:end func_L01_00340458 */
