#include "common.h"

/* localdecomp:start func_L07_003B90F0 */
void func_L01_004450F0(void *, s32, s32);
void func_L01_004AA7E8(void *, s32);

void func_L07_003B90F0(u8 *arg0) {
    u8 *a24;
    s32 t;

    switch (*(u8 *)(arg0 + 0x20)) {
    case 0:
        *(u8 *)(arg0 + 0x30) = 0xFF;
        t = *(u16 *)(arg0 + 0x34);
        a24 = *(u8 **)(arg0 + 0x24);
        t = t & 0xFFBE;
        *(u16 *)(arg0 + 0x34) = t;
        t = t | (*(u16 *)(a24 + 0x44) & 0x1000);
        *(u16 *)(arg0 + 0x34) = t;
        t = t | 2;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(a24 + 0x10);
        *(s32 *)(arg0 + 0x98) = *(s32 *)(a24 + 0x10);
        *(u16 *)(arg0 + 0x34) = t;
        func_L01_004450F0(arg0, 1, -1);
        break;
    case 1:
        break;
    case 2:
        *(s32 *)(arg0 + 0x98) = 0;
        *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(arg0, 1);
        *(s32 *)(arg0 + 0x98) = 0;
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) | 2;
        break;
    }
}
/* localdecomp:end func_L07_003B90F0 */

/* localdecomp:start func_L07_003B91C8 */
/* localdecomp:start func_L07_003B91C8 */
typedef struct { u8 kind[8], extra[8]; s16 a[8], b[8], c[8], d[8]; s32 params[8]; s32 index1, index3, index2, slot; u8 *target; } Data_003B91C8;
extern s16 *D_L07_0021C020[];

extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern s32 D_L07_001DF458;
extern s32 func_L07_003A7178_003B91C8(u8 *, u8 *, s32, u8, s32);
extern s32 func_L07_003BA000_003B91C8(u8 *, u8 *, u8, s32, u8, s32);
extern s32 func_L07_003A6C90(u8 *, u8 *, s16, s16, s16, s16, s32, u8, s32);

void func_L07_003B91C8(u8 *moby, s32 slot, s32 arg) {
    Data_003B91C8 *data;
    s16 *p;
    u8 *target;
    s32 result;
    s16 *p1;
    u8 *target1;
    *(u16 *)(moby + 0x34) &= 0xFFFD;
    data = *(Data_003B91C8 **)(moby + 0x68);
    data->slot = slot;
    switch (data->kind[slot]) {
    case 0: break;
found1:
    data->target = target1;
    goto done;
found:
    data->target = target;
    goto done;
    case 1:
        p1 = D_L07_0021C020[data->index1];
        while ((data->index1 & 255) != 255 &&
               data->index1 <= D_L07_001DF458 && p1 != 0 &&
               (p1[-1] >= 0 || p1 == D_L07_0021C020[data->index1])) {
            target1 = D_L07_001DF41C + ((*p1 & 0x7FFF) << 8);
            if (target1 == 0) break;
            result = func_L07_003A7178_003B91C8(target1, moby + 0x10, arg, moby[0x21], data->params[slot]);
            if (result) {
                goto found1;
            }
            p1++;
        }
        break;
    case 2:
        p = D_L07_0021C020[data->index2];
        while ((data->index2 & 255) != 255 &&
               data->index2 <= D_L07_001DF458 && p != 0 &&
               (p[-1] >= 0 || p == D_L07_0021C020[data->index2])) {
            target = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
            if (target == 0) break;
            result = func_L07_003BA000_003B91C8(target, moby + 0x10, data->extra[slot], arg, moby[0x21], data->params[slot]);
            if (result) {
                goto found;
            }
            p++;
        }
        break;
    case 3:
        p = D_L07_0021C020[data->index3];
        while ((data->index3 & 255) != 255 &&
               data->index3 <= D_L07_001DF458 && p != 0 &&
               (p[-1] >= 0 || p == D_L07_0021C020[data->index3])) {
            target = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
            if (target == 0) break;
            result = func_L07_003A6C90(target, moby + 0x10, data->d[slot], data->a[slot], data->b[slot], data->c[slot], arg, moby[0x21], data->params[slot]);
            if (result) {
                goto found;
            }
            p++;
        }
        break;
    }
done:
    func_L01_004450F0(moby, 2, -1);
}
/* localdecomp:end func_L07_003B91C8 */
/* localdecomp:end func_L07_003B91C8 */

/* localdecomp:start func_L07_003B94E0 */
void func_L07_003A71E8(s32);
void func_L07_003BA098(s32);
void func_L07_003A6EA8(s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003B94E0(void *arg0) {
    void *temp_s0;
    u8 kind;

    *(u16 *)((u8 *)arg0 + 0x34) = (u16)(*(u16 *)((u8 *)arg0 + 0x34) & 0xFFFD);
    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    kind = *(u8 *)((u8 *)temp_s0 + *(s32 *)((u8 *)temp_s0 + 0x7C));
    switch (kind) {
    case 1:
        func_L07_003A71E8(*(s32 *)((u8 *)temp_s0 + 0x80));
        break;
    case 2:
        func_L07_003BA098(*(s32 *)((u8 *)temp_s0 + 0x80));
        break;
    case 3:
        func_L07_003A6EA8(*(s32 *)((u8 *)temp_s0 + 0x80));
        break;
    case 0:
    default:
        break;
    }
    *(s32 *)((u8 *)temp_s0 + 0x7C) = 0;
    func_L01_004450F0(arg0, 0, -1);
}
/* localdecomp:end func_L07_003B94E0 */

/* localdecomp:start func_L07_003B9590 */
typedef int Q_003B9590 __attribute__((mode(TI)));
typedef struct {
    s32 w0;
    u8 p4[0x2C];
    s32 on[4];
    s32 handle[4];
    u8 p50[0x10];
    s32 w60;
} P_003B9590;

extern u8 D_001A4C60[];
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L01_003F2A50(s32, s32);
void func_L01_003F2AF8(s32, s32);
void func_L07_003B98E0(void *);
void func_L07_003B96F8(u8 *, s32);

void func_L07_003B9590(u8 *a0) {
    Q_003B9590 v;
    P_003B9590 *p;
    s32 i;
    s32 h;

    v = *(Q_003B9590 *)D_001A4C60;
    p = *(P_003B9590 **)(a0 + 0x68);
    i = 0;
    switch (a0[0x20]) {
    case 0:
        func_L07_003B98E0(a0);
        break;
    case 1:
        break;
    case 2:
        if (func_00382380(&v, p->w0, 0) && p->on[i] == 0
            && (p->w60 == -1 || func_L01_00445AD0(p->w60, -1, 0))) {
            h = func_L01_003F2A50(0, 5);
            p->on[i] = 1;
            p->handle[i] = h;
            func_L07_003B96F8(a0, i);
        } else if (p->on[i] != 0) {
            if (!func_00382380(&v, p->w0, 0)
                || (p->w60 != -1 && !func_L01_00445AD0(p->w60, -1, 0))) {
                func_L01_003F2AF8(0, p->handle[i]);
                p->on[i] = 0;
            }
        }
        break;
    }
}
/* localdecomp:end func_L07_003B9590 */

/* localdecomp:start func_L07_003B96F8 */
typedef int Q_003B96F8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x40]; u8 *targets[1]; } Data_003B96F8;
void func_L07_003B96F8(u8 *moby, s32 index) {
    Data_003B96F8 *data = *(Data_003B96F8 **)(moby + 0x68);
    if (*(f32 *)((u8 *)data + 4) != -1.0f)
        *(f32 *)(data->targets[index] + 0) = *(f32 *)((u8 *)data + 4);
    if (*(f32 *)((u8 *)data + 8) != -1.0f)
        *(f32 *)(data->targets[index] + 4) = *(f32 *)((u8 *)data + 8);
    if (*(f32 *)((u8 *)data + 12) != -1.0f)
        *(f32 *)(data->targets[index] + 8) = *(f32 *)((u8 *)data + 12);
    if (*(f32 *)((u8 *)data + 16) != -1.0f)
        *(f32 *)(data->targets[index] + 12) = *(f32 *)((u8 *)data + 16);
    if (*(f32 *)((u8 *)data + 20) != -1.0f)
        *(f32 *)(data->targets[index] + 16) = *(f32 *)((u8 *)data + 20);
    if (*(f32 *)((u8 *)data + 24) != -1.0f)
        *(f32 *)(data->targets[index] + 20) = *(f32 *)((u8 *)data + 24);
    if (*(s16 *)((u8 *)data+0x1C) != -1)
        *(u8 *)(data->targets[index]+0x18) = *(s16 *)((u8 *)data+0x1C);
    if (*(s16 *)((u8 *)data+0x1E) != -1)
        *(u16 *)(data->targets[index]+0x1A) = *(s16 *)((u8 *)data+0x1E);
    if (((u8 *)data)[32] != 0)
        (data->targets[index])[28] = ((u8 *)data)[32];
    if (((u8 *)data)[33] != 0)
        (data->targets[index])[29] = ((u8 *)data)[33];
    if (((u8 *)data)[34] != 0)
        (data->targets[index])[30] = ((u8 *)data)[34];
    if (((u8 *)data)[35] != 0)
        (data->targets[index])[31] = ((u8 *)data)[35];
    if (*(s16 *)((u8 *)data+36) != -1)
        *(u16 *)(data->targets[index]+48) = *(s16 *)((u8 *)data+36);
    if (*(s16 *)((u8 *)data+38) != -1)
        *(u16 *)(data->targets[index]+50) = *(s16 *)((u8 *)data+38);
    if (*(f32 *)((u8 *)data+0x50) != -1.0f)
        *(Q_003B96F8 *)(data->targets[index]+0x20) = *(Q_003B96F8 *)((u8 *)data+0x50);
}
/* localdecomp:end func_L07_003B96F8 */

/* localdecomp:start func_L07_003B98E0 */
void func_L01_003F2AF8(s32, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003B98E0(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_s0 + 0x30)) != 0) {
        func_L01_003F2AF8(0, (*(s32 *)((u8 *)temp_s0 + 0x40)));
        *(s32 *)((u8 *)temp_s0 + 0x30) = 0;
    }
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 2);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003B98E0 */

/* localdecomp:start func_L07_003B9948 */
extern void func_L01_004450F0(void *, int, int);

void func_L07_003B9948(char *arg0, unsigned char idx)
{
    if (*(unsigned char *)(*(char **)(arg0 + 0x68) + idx + 0x64) != 0) {
        *(unsigned short *)(arg0 + 0x34) &= 0xFFFD;
        func_L01_004450F0(arg0, 2, -1);
    }
}
/* localdecomp:end func_L07_003B9948 */
