#include "common.h"

typedef struct Obj_004CE458 Obj_004CE458;
typedef struct {
    u8 pad[8];
    void (*fn8)(Obj_004CE458 *);
} Vt_004CE458;
struct Obj_004CE458 {
    u8 pad[36];
    Vt_004CE458 *vt;
    u8 pad2[20];
};

/* localdecomp:start func_L01_004D24C0 */
typedef struct {
    u8 pad[0xB0];
    f32 fB0;
} S_004D24C0;

extern S_004D24C0 D_L01_001E7580;
extern s32 D_001D52F0;
extern s32 D_001D545C_004D24C0;
extern s32 D_L01_002D15F0[];
extern char *D_L01_001D67C8;
extern s32 D_L01_001DB784;
__asm__(".extern D_L01_001DB784, 4");
extern s32 D_L01_001DB788;
extern void func_003873C0(void);
extern void func_L01_004D1700(char *, s32);
extern u32 func_L01_004D0CB0(void *);
extern void func_L01_004D21E0(char *, s32, s32, s32, u32);
extern void func_003AD278(void *);
extern void func_L01_004365D0_004D24C0(void);
extern void func_L01_004D2110_004D24C0(char *);

void func_L01_004D24C0(char *m) {
    f32 save;
    u32 r;
    char *p;

    save = D_L01_001E7580.fB0;
    D_L01_001E7580.fB0 = 0.62f;
    func_003873C0();
    func_L01_004D2110_004D24C0(m);
    if (D_001D545C_004D24C0 != -2) {
        func_L01_004D1700(m + (D_001D52F0 * 0xB50 + 0x18A0), D_001D52F0);
    }
    if (D_L01_002D15F0[0] == 0) {
        if (D_001D545C_004D24C0 != -2) {
            r = func_L01_004D0CB0(m + (D_001D52F0 * 0xB50 + 0x18A0));
            func_L01_004D21E0(m, D_001D52F0, D_L01_001DB784, D_L01_001DB788, r >> 24);
        }
    }
    p = D_L01_001D67C8;
    *(s32 *)(p + 0x24DD4) = 0;
    *(s32 *)(p + 0x24DD8) = 0;
    func_003AD278(m + 0x4ED0);
    func_L01_004365D0_004D24C0();
    D_L01_001E7580.fB0 = save;
    func_003873C0();
}
/* localdecomp:end func_L01_004D24C0 */
