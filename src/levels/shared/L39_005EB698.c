#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005EB698);

INCLUDE_ASM("asm/levels", func_L39_005EBAF0);

INCLUDE_ASM("asm/levels", func_L39_005EBCB8);

/* localdecomp:start func_L39_005EBDA0 */
extern s32 func_L01_00517688(void);
typedef struct { u8 pad[0x4500]; } D_002FB100_t;
extern D_002FB100_t *func_L39_0061BF38(s32 i);
typedef struct { s32 v[4]; } S_005EBDA0;
extern s32 D_L39_0024C878;
extern s32 D_L39_0024C868[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024C868, 4");
extern s32 D_001D865C_sda;
extern s32 D_001D8660_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8660_sda, 4");
extern s32 D_001D8658_sda;
extern s32 D_001D8580_sda;
typedef struct { u8 pad[0x1C0]; s32 held; s32 pressed; } P_005EBDA0;
typedef struct { u8 pad[0x2534]; P_005EBDA0 *pad_; } Q_005EBDA0;

s32 func_L39_005EBDA0(void) {
    s32 idx;
    Q_005EBDA0 *p;
    s32 a, b;
    if (D_L39_0024C878 == 0) {
        D_L39_0024C878 = 1;
        *(S_005EBDA0 *)D_L39_0024C868 = (S_005EBDA0){ { D_001D865C_sda, D_001D865C_sda, D_001D865C_sda, D_001D865C_sda } };
    }
    idx = func_L01_00517688();
    p = (Q_005EBDA0 *)func_L39_0061BF38(idx);
    a = p->pad_->held;
    b = p->pad_->pressed;
    if (a != 0 && a == D_001D8660_sda[idx]) {
        if (--D_L39_0024C868[idx] == 0 || D_L39_0024C868[idx] == 0xFF) {
            D_L39_0024C868[idx] = D_001D8658_sda;
            b = p->pad_->held & D_001D8580_sda;
        }
    } else {
        D_L39_0024C868[idx] = D_001D865C_sda;
    }
    D_001D8660_sda[idx] = p->pad_->held;
    return b;
}
/* localdecomp:end func_L39_005EBDA0 */
