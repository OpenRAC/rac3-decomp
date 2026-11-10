#include "common.h"

/* localdecomp:start func_L39_006B7CD8 */
typedef struct VT_006B7CD8 { u8 pad[0xF0]; void (*f)(void *); } VT_006B7CD8;
typedef struct O_006B7CD8 { u8 pad[0x60]; VT_006B7CD8 *vt; } O_006B7CD8;
extern s32 D_001DDA44_sda;
extern s32 D_001DDA64_sda;
extern u8 D_001D82EC_sda;
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern u8 D_L39_0037C848[];
extern void func_L39_006B6BD0(void);
extern void func_L39_006B6C30(void);
extern void func_L01_004792D8(void (*)(void));
extern void func_L39_005BF798(int, int, int, int, int);
extern void func_L39_00689A70(void);

void func_L39_006B7CD8(O_006B7CD8 *arg0) {
    VT_006B7CD8 *vt;
    u8 *e = D_L39_0037C848 + D_001DDA44_sda * 0x1F0;

    e[0xEC] = 1;
    if (!(e[0x50] & 1)) {
        e[0x3D] = 0;
    }
    func_L39_006B6BD0();
    func_L01_004792D8(func_L39_006B6C30);
    D_001D82EC_sda = 0;
    func_L39_005BF798(0x12, 1, 1, 0, 0);
    vt = arg0->vt;
    D_00241440 = 1;
    vt->f(arg0);
    func_L39_00689A70();
    D_001DDA64_sda = 0;
}
/* localdecomp:end func_L39_006B7CD8 */
