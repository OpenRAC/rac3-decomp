#include "common.h"

/* localdecomp:start func_L39_0050D3D8 */
typedef struct S_0050D3D8 {
    u8 *data;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} S_0050D3D8;

extern s32 func_L39_0050FDC8(s32 *, s32 *, s32 *, void *, u8 *, s32);
extern s32 func_L39_004F7560(void *, u8 *, u32);

s32 func_L39_0050D3D8(u32 *outlen, void *dst, u32 max, u8 *data, u32 size) {
    S_0050D3D8 buf;
    s32 len;
    s32 tag;
    s32 hdr;
    u32 off;
    s32 ret;

    for (off = 0; off < size; off += len) {
        ret = func_L39_0050FDC8(&len, &tag, &hdr, &buf, data + off, size - off);
        if (ret != 0) return ret;
        ret = func_L39_004F7560(dst, data + off, (u32)len > max ? max : len);
        if (ret < 0 || (ret == 0 && (u32)len > max)) {
            *outlen = off;
            return 0;
        }
    }
    *outlen = size;
    return 0;
}
/* localdecomp:end func_L39_0050D3D8 */

/* localdecomp:start func_L39_0050D4C0 */
typedef struct S_0050D4C0 {
    u8 *data;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} S_0050D4C0;

extern s32 func_L39_0050FDC8(s32 *, s32 *, s32 *, void *, u8 *, s32);
s32 func_L39_0050D4C0(s32 *len, u8 *data, s32 max);

s32 func_L39_0050D4C0(s32 *len, u8 *data, s32 max) {
    S_0050D4C0 buf;
    s32 tag;
    s32 hdr;
    s32 sub;
    s32 off;
    s32 h;
    s32 ret;

    ret = func_L39_0050FDC8(len, &tag, &hdr, &buf, data, max);
    if (ret != 0) return ret;
    if (*len != 0) return ret;
    off = 0;
    h = hdr + 4;
    while (buf.data[off] != 0 || buf.data[off + 1] != 0) {
        ret = func_L39_0050D4C0(&sub, buf.data + off, max - (off + h));
        if (ret != 0) return ret;
        off += sub;
    }
    *len = off + h;
    return 0;
}
/* localdecomp:end func_L39_0050D4C0 */
