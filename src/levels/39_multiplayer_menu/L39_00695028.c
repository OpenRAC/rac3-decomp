#include "common.h"

/* localdecomp:start func_L39_00695028 */
typedef struct V_00695028 V_00695028;
typedef struct { u8 pad[0x60]; V_00695028 *vt; } O_00695028;
struct V_00695028 {
    u8 pad0[0x1C];
    void (*show)(O_00695028 *, s32, s32);
    u8 pad1[0x40 - 0x20];
    void (*setSel)(O_00695028 *, s32);
    u8 pad2[0xB8 - 0x44];
    void (*setText)(O_00695028 *, s32);
};
typedef struct {
    u8 pad0[0x114];
    O_00695028 *f114;
    u8 pad1[0x2A8 - 0x118];
    s32 f2a8;
    u8 f2ac;
    s32 f2b0;
} S_00695028;
typedef struct { u8 pad[0x38]; void *f38; } G_00695028;
__asm__(".extern D_L39_0024D760, 16");
extern G_00695028 *D_L39_0024D760;
extern u8 D_L39_00247F60[];
s32 func_00381FF0(s32);
void func_L39_0067F100(s32);
void func_L39_00689BD8(void *, s32);
void func_L39_00689D28(void *, u8 *);
void func_L39_00689DB8(void *, s32);
void func_L39_0068A9B8(s32);
void func_L39_0068AAB8(void *);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
s32 func_L39_006CEA18(void *, s32);

void func_L39_00695028(S_00695028 *p)
{
    func_L39_0067F100(0x280000);
    func_L39_00689BD8(p, func_00381FF0(0xFCE));
    func_L39_00689D28(p, D_L39_00247F60);
    func_L39_00689DB8(p, func_00381FF0(0xCD5));
    func_L39_0068A9B8(0);
    func_L39_0068A6D0(p, 0, 0.5f, 0.27f, 0.82f, 0.27f, 0x332299DE);
    func_L39_0068A6D0(p, 1, 0.5f, 0.635f, 0.82f, 0.45f, 0x332299DE);
    func_L39_0068AAB8(p);
    p->f114->vt->setText(p->f114, func_00381FF0(0x1010));
    p->f114->vt->show(p->f114, 2, 0);
    p->f114->vt->setSel(p->f114, 1);
    p->f2b0 = 0;
    p->f2a8 = 0;
    func_L39_006CEA18(D_L39_0024D760->f38, 0);
    p->f2ac = 1;
}
/* localdecomp:end func_L39_00695028 */
