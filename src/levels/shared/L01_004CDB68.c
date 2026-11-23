#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_004CDB68);

/* localdecomp:start func_L01_004CDB70 */
/* localdecomp:start func_L01_004CDB70 */
extern s32 D_001D55E8;
extern void func_0038E150(s32);
extern s32 func_L01_00412750_004CDB70(void *, s32);
extern s32 func_L01_00412708_004CDB70(void *, s32);

void func_L01_004CDB70(u8 *obj, s32 mode, s32 arg, f32 x, f32 y)
{
    u8 *inner = obj + 0x88;
    s32 saved;

    (*(f32 **)obj)[0] = x;
    (*(f32 **)obj)[1] = y;
    obj[0x187] = 0;
    *(u8 **)(obj + 0x1B8) = inner;
    saved = D_001D55E8;
    *(s32 *)(obj + 0x1A4) = mode;
    *(s32 *)(obj + 0x198) = arg;
    func_0038E150(1);
    switch (*(s32 *)(obj + 0x1A4)) {
    case 0:
        *(s32 *)(obj + 0x1B4) = func_L01_00412750_004CDB70(inner, -1);
        break;
    case 1:
        *(s32 *)(obj + 0x1B4) = func_L01_00412708_004CDB70(inner, -1);
        break;
    case 2:
        break;
    }
    func_0038E150(saved);
    *(s32 *)(obj + 0x190) = 1;
    **(f32 **)(obj + 4) = 1.0f;
}
/* localdecomp:end func_L01_004CDB70 */
/* localdecomp:end func_L01_004CDB70 */

/* localdecomp:start func_L01_004CDC38 */
typedef struct {
    f32 x;
    f32 y;
} Pos_4CDC38_004CDC38;
typedef struct {
    Pos_4CDC38_004CDC38 *pos;
    f32 *scale;
    u8 pad8[0x80];
    u8 text[0x108];
    s32 lineCount;
    s32 pad194;
    s32 f198;
    s32 pad19C[2];
    s32 mode;
    s32 pad1A8[3];
    s32 maxWidth;
    u8 *lines[0x1E];
} Text_4CDC38_004CDC38;

extern s32 func_0011A264(void *, s32, s32);
extern s32 D_001D55E8;
extern void func_0038E150(s32);
extern s32 func_L01_00412708_004CDC38(u8 *, s32);
extern s32 func_L01_00412750_004CDC38(u8 *, s32);

void func_L01_004CDC38(void *arg0, s32 mode, s32 arg2, f32 x, f32 y) {
    Text_4CDC38_004CDC38 *self = arg0;
    u8 buf[0x100];
    s32 saved;
    s32 width = 1;
    s32 pos = 0;
    s32 single = 1;
    s32 i = 0;

    self->pos->x = x;
    self->pos->y = y;
    self->f198 = arg2;
    self->mode = mode;
    self->text[0xFF] = 0;
    self->lineCount = 1;
    self->maxWidth = 0;
    func_0011A264(buf, 0, 0x100);
    func_0011A264(self->lines, 0, 0x78);
    saved = D_001D55E8;
    self->lines[self->lineCount - 1] = self->text;
    func_0038E150(1);
    for (; i < 0xFF && self->text[i] != 0; i++) {
        if (self->text[i] == 1) {
            self->text[i] = 0;
            buf[pos] = 0;
            single = 0;
            self->lines[self->lineCount] = &self->text[i + 1];
            self->lineCount++;
            if (self->mode != 1) {
                if (self->mode < 2) {
                    if (self->mode == 0) {
                        width = func_L01_00412750_004CDC38(buf, -1);
                    }
                }
            } else {
                width = func_L01_00412708_004CDC38(buf, -1);
            }
            pos = 0;
            self->maxWidth = (self->maxWidth < width) ? width : self->maxWidth;
        } else {
            buf[pos] = self->text[i];
            pos++;
        }
    }
    if (single) {
        if (self->mode != 1) {
            if (self->mode < 2) {
                if (self->mode == 0) {
                    self->maxWidth = func_L01_00412750_004CDC38(buf, -1);
                }
            }
        } else {
            self->maxWidth = func_L01_00412708_004CDC38(buf, -1);
        }
    } else {
        if (self->mode != 1) {
            if (self->mode < 2) {
                if (self->mode == 0) {
                    width = func_L01_00412750_004CDC38(buf, -1);
                }
            }
        } else {
            width = func_L01_00412708_004CDC38(buf, -1);
        }
        self->maxWidth = (self->maxWidth < width) ? width : self->maxWidth;
    }
    func_0038E150(saved);
    *self->scale = 1.0f;
}
/* localdecomp:end func_L01_004CDC38 */

/* localdecomp:start func_L01_004CDEA8 */
extern s32 func_11BB58(void *, s32, s32);
extern void func_L01_004CDC38(void *, s32, s32, f32, f32);

void func_L01_004CDEA8(u8 *object, s32 value, s32 count)
{
    s32 limit = (count == -1) ? 300 : count;
    u8 *inner = object + 0x4ED0;

    func_11BB58((void *)(object + 0x4F58), value, 255);
    func_L01_004CDC38((void *)inner, 1, limit, 255.0f, 80.0f);
}
/* localdecomp:end func_L01_004CDEA8 */

/* localdecomp:start func_L01_004CDF10 */
void func_L01_004CDF10(u8 *a0) {
    **(s32 **)(a0 + 20180) = 0;
}
/* localdecomp:end func_L01_004CDF10 */
