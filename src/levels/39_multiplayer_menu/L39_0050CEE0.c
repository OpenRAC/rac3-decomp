#include "common.h"

/* localdecomp:start func_L39_0050CEE0 */
typedef struct S_0050CEE0 {
    u8 *unk0;
    u32 len;
    u32 flags;
    s32 unkC;
} S_0050CEE0;

extern u8 D_L39_0046F408[];
extern s32 func_L39_005108A0(u8 *, u32 *, s32, u32, s32, s32, u32);
s32 func_L39_0050CEE0(u32 *len, s32 *count, S_0050CEE0 **nodes);

s32 func_L39_0050CEE0(u32 *len, s32 *count, S_0050CEE0 **nodes) {
    u32 sublen;
    s32 subcount;
    s32 i;
    s32 r;

    *len = 0;
    if (nodes[0]->unk0 == D_L39_0046F408) {
        i = 1;
        while (nodes[i]->flags != 0x103) {
            r = func_L39_0050CEE0(&sublen, &subcount, &nodes[i]);
            if (r != 0) {
                return r;
            }
            *len += sublen;
            if (*len < sublen) {
                return 0x802;
            }
            i += subcount;
        }
        *count = i + 1;
    } else {
        i = 0;
        while (nodes[i]->flags & 0x800) {
            *len += nodes[i]->len;
            if (*len < nodes[i]->len) {
                return 0x802;
            }
            i++;
        }
        *len += nodes[i]->len;
        if (*len < nodes[i]->len) {
            return 0x802;
        }
        *count = i + 1;
        if ((nodes[i]->flags & 0x1FF) == 0x100) {
            return 0;
        }
    }
    func_L39_005108A0(0, &sublen, 0, nodes[0]->flags, nodes[0]->unkC, 0, *len);
    *len += sublen;
    if (*len < sublen) {
        return 0x802;
    }
    return 0;
}
/* localdecomp:end func_L39_0050CEE0 */

/* localdecomp:start func_L39_0050D0C0 */
typedef struct S_0050D0C0 {
    u8 *unk0;
    u32 len;
    u32 flags;
    s32 unkC;
} S_0050D0C0;

extern u8 D_L39_0046F408[];
extern void func_L39_004F7510(u8 *, u8 *, u32);
extern s32 func_L39_004F7538(void *, void *, s32);
extern s32 func_L39_0050D3D8(u32 *, void *, u32, u8 *, u32);
extern s32 func_L39_005108A0(u8 *, u32 *, s32, u32, s32, s32, u32);
void func_L39_0050D0C0(u8 *buf, u32 *len, s32 size, s32 *count, S_0050D0C0 **nodes, s32 idx);

void func_L39_0050D0C0(u8 *buf, u32 *len, s32 size, s32 *count, S_0050D0C0 **nodes, s32 idx) {
    u32 sublen;
    s32 subcount;
    u32 extra;
    s32 i;

    *len = 0;
    extra = 0;
    if (nodes[idx]->flags == 0x103) {
        i = idx - 1;
        while (nodes[i]->unk0 != D_L39_0046F408) {
            func_L39_0050D0C0(buf, &sublen, size - *len, &subcount, nodes, i);
            if (nodes[idx]->unk0 == &D_L39_0046F408[1]) {
                func_L39_0050D3D8(&extra, (buf + size) - (*len + sublen), sublen, (buf + size) - *len, *len);
                if (extra != 0) {
                    func_L39_004F7538((buf + size) - (*len + sublen), (buf + size) - *len, extra);
                    func_L39_0050D0C0((buf + size) - (*len + sublen) + extra, &sublen, sublen, &subcount, nodes, i);
                }
            }
            *len += sublen;
            i -= subcount;
        }
        *count = idx - i + 1;
    } else {
        i = idx;
        func_L39_004F7510((buf + size) - nodes[idx]->len, nodes[idx]->unk0, nodes[idx]->len);
        *len += nodes[idx]->len;
        while (i != 0 && (nodes[i - 1]->flags & 0x800)) {
            i--;
            func_L39_004F7510((buf + size) - (*len + nodes[i]->len), nodes[i]->unk0, nodes[i]->len);
            *len += nodes[i]->len;
        }
        *count = idx - i + 1;
        if ((nodes[i]->flags & 0x1FF) == 0x100) {
            return;
        }
    }
    func_L39_005108A0(0, &sublen, 0, nodes[i]->flags, nodes[i]->unkC, 0, *len);
    func_L39_005108A0((buf + size) - (*len + sublen), &sublen, sublen, nodes[i]->flags, nodes[i]->unkC, 0, *len);
    *len += sublen;
}
/* localdecomp:end func_L39_0050D0C0 */
