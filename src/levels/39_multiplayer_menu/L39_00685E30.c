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

/* localdecomp:start func_L39_00685E30 */
extern s32 func_L01_00521C90(s32, s32);
extern void *func_L39_00687968(void *);
extern s32 func_L39_00686810(void *, s32);
extern s32 func_L39_006D82B8(void *, s32);
extern s32 func_L39_006D8338(void *, s32);
extern s32 func_L39_006D83B8(void *, s32);
extern s32 func_L39_006D84B8(void *, s32);
extern s32 func_L39_006D8538(void *, s32);
extern s32 func_L39_006D8638(void *, s32);
extern s32 func_L39_006D85B8(void *, s32);
extern s32 func_L39_006D8738(void *, s32);
extern s32 func_L39_006D87B8(void *, s32);
extern s32 func_L39_006D8228(void *, s32);
extern s32 func_L39_006D8838(void *, s32);
extern s32 func_L39_006D88B8(void *, s32);
extern s32 func_L39_006D8438(void *, s32);
extern s32 func_L39_006D86B8(void *, s32);
extern s32 func_L39_006D8198(void *, s32);
extern void func_L39_0067F210(void);

typedef struct {
    u8 pad0[0x64];
    s32 f64[0x20];
    s32 fE4;
} S_00685E30;

__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
__asm__(".extern D_L39_0024D764, 16");
extern u8 D_L39_0024D764;
__asm__(".extern D_L39_0024D765, 16");
extern u8 D_L39_0024D765;
__asm__(".extern D_001DC204_sda, 4");
extern S_00685E30 *D_001DC204_sda;
__asm__(".extern D_001DC208_sda, 4");
extern s32 D_001DC208_sda;
__asm__(".extern D_001DC20C_sda, 4");
extern s32 D_001DC20C_sda;

void func_L39_00685E30(s32 arg0, s32 arg1) {
    s32 i;

    D_001DC20C_sda = arg1;
    D_001DC208_sda = arg0;
    D_001DC204_sda = func_L39_00687968((void *)func_L01_00521C90(0x29C, arg0));
    D_001DC208_sda += 0x29C;
    D_001DC20C_sda -= 0x29C;
    for (i = 0; i < 0x2B; i++) {
        if (i == 0x20) {
            D_001DC204_sda->fE4 = D_001DC204_sda->f64[0x1F];
        } else {
            D_001DC204_sda->f64[i] = func_L39_00686810(D_001DC204_sda, i);
        }
    }
    func_L39_006D82B8(D_L39_0024D760, 0x40);
    func_L39_006D8338(D_L39_0024D760, 0x40);
    func_L39_006D83B8(D_L39_0024D760, 0x40);
    func_L39_006D84B8(D_L39_0024D760, 0x40);
    func_L39_006D8538(D_L39_0024D760, 6);
    func_L39_006D8638(D_L39_0024D760, 0x40);
    func_L39_006D85B8(D_L39_0024D760, 0x40);
    func_L39_006D8738(D_L39_0024D760, 0x10);
    func_L39_006D87B8(D_L39_0024D760, 0x10);
    func_L39_006D8228(D_L39_0024D760, 0xE0);
    func_L39_006D8838(D_L39_0024D760, 0xE0);
    func_L39_006D88B8(D_L39_0024D760, 0x100);
    func_L39_006D8438(D_L39_0024D760, 0xF);
    func_L39_006D86B8(D_L39_0024D760, 0xA);
    func_L39_006D8198(D_L39_0024D760, 0x32);
    *(void **)(D_L39_0024D760 + 0x20) = func_L39_0067F210;
    D_L39_0024D765 = 1;
    D_L39_0024D764 = 0;
}
/* localdecomp:end func_L39_00685E30 */
