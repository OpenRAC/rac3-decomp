/* Adapted from nonmatching/boot_elf/func_003B8390.c, NTSC decomp
 * commit 13cf5c5 draft. Native globals, call addresses and switch table
 * checked against owned NTSC retail. All callees have explicit prototypes. */
#include "common.h"

/* localdecomp:start func_U_003B82B8 */
typedef struct {
    s16 field0;
    u16 field2;
    s16 field4, field6, field8, fieldA, fieldC, fieldE, field10;
    u16 field12;
    s16 field14, field16, field18, field1A;
} Dialog_B82B8;
extern s32 D_001D4CE8;
extern u8 D_U_001DA020;
extern u8 D_U_001D5BDC;
extern u8 D_U_001D5BDD;
extern u16 D_001D4BC4;
extern char D_U_001D8B78[];
extern char D_U_001D8B80[];
extern char D_U_00280B70[];
extern char *func_U_003823F0(s32);
extern char *func_U_00382488(s32);
extern void func_U_0038E478(s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_U_003AF620(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_0011B2E8(char *, const char *, ...);

void func_U_003B82B8(void) {
    Dialog_B82B8 dialog;
    Dialog_B82B8 template;
    char *first = 0;
    char *second = 0;
    char *caption;
    s32 draw = 1;
    func_U_0038E478(0);
    caption = D_U_001D8B78;
    switch (D_001D4CE8) {
    case 8:
        first = func_U_003823F0(0x8E3);
        second = func_U_003823F0(0x8DF);
        caption = func_U_003823F0(0x1A3);
        break;
    case 14:
        if (D_U_001DA020 == 0) break;
        caption = func_U_00382488(0x195);
        first = func_U_003823F0(0x197);
        break;
    case 15:
        first = func_U_003823F0(0x8E3);
        second = func_U_003823F0(0x8DF);
        caption = func_U_00382488(0x19F);
        break;
    case 33:
        first = func_U_003823F0(0x8E3);
        second = func_U_003823F0(0x8DF);
        caption = func_U_00382488(0x1A8);
        break;
    case 12: case 13: case 31: case 32:
        caption = func_U_00382488(0x1AF);
        break;
    case 9: case 10:
        caption = func_U_00382488(0x1AD);
        break;
    case 16: case 17:
        caption = func_U_00382488(0x1AE);
        break;
    case 25: case 29:
        caption = func_U_00382488(0x1AB);
        break;
    case 23: case 30:
        caption = func_U_00382488(0x1AC);
        break;
    case 19:
        caption = func_U_00382488(0x1B0);
        first = func_U_003823F0(0x8DE);
        break;
    case 20:
        caption = func_U_00382488(0x1B2);
        first = func_U_003823F0(0x8DE);
        break;
    case 3:
        caption = func_U_00382488(0x194);
        break;
    case 21:
        if (D_U_001DA020 != 0) {
            caption = func_U_00382488(0x195);
            first = func_U_003823F0(0x197);
        } else if (D_U_001D5BDC != 0) {
            char *buffer = D_U_00280B70;
            char *format = D_U_001D8B80;
            char *text = func_U_003823F0(0x198);
            func_0011B2E8(buffer, format, text, 1, 1, func_U_003823F0(0x19A));
            caption = buffer;
            first = func_U_003823F0(0x8E2);
            second = func_U_003823F0(0x8DF);
        } else {
            char *buffer = D_U_00280B70;
            char *format = D_U_001D8B80;
            char *text = func_U_003823F0(0x198);
            func_0011B2E8(buffer, format, text, 1, 1, func_U_00382488(0x19A));
            caption = buffer;
            first = func_U_003823F0(0x8E2);
        }
        break;
    case 24:
        if (D_U_001D5BDC) caption = func_U_00382488(0x1B2);
        else caption = func_U_00382488(0x1B3);
        first = func_U_003823F0(0x8DE);
        break;
    case 22:
        caption = func_U_00382488(0x1B1);
        first = func_U_003823F0(0x8DE);
        break;
    case 27: {
        char *buffer;
        char *format;
        char *text;
        first = func_U_003823F0(0x8E2);
        second = func_U_003823F0(0x8DF);
        buffer = D_U_00280B70;
        format = D_U_001D8B80;
        text = func_U_00382488(0x1A1);
        func_0011B2E8(buffer, format, text, 1, 1, func_U_00382488(0x19A));
        caption = buffer;
        break;
    }
    case 26:
        first = func_U_003823F0(0x8E2);
        second = func_U_003823F0(0x8DF);
        caption = func_U_00382488(0x1A5);
        break;
    case 4: case 5: case 6:
        if (D_U_001D5BDC != 0 && D_U_001DA020 == 0) {
            first = func_U_003823F0(0x8E2);
            second = func_U_003823F0(0x8DF);
            caption = func_U_00382488(0x19B);
        } else if (D_U_001D5BDD != 0) {
            first = func_U_003823F0(0x8E3);
            caption = func_U_00382488(0x19B);
        } else if (D_U_001DA020 == 0) {
            caption = func_U_00382488(0x19D);
            first = func_U_003823F0(0x197);
        } else {
    case 7:
            caption = func_U_00382488(0x195);
            first = func_U_003823F0(0x197);
        }
        break;
    case 11: case 18: case 28:
    default:
        draw = 0;
        break;
    }
    if (draw) {
        func_0011A264(&template, 0, 0x1C);
        template.field2 = D_001D4BC4;
        template.field4 = 0x60;
        template.field6 = 0x1A0;
        template.field8 = 0x100;
        template.fieldA = 0x68;
        template.field10 = 0x10;
        template.field12 = 1;
        dialog = template;
        func_U_0038E478(1);
        func_U_003AF620(&dialog, 0x8066CCFF, caption, 1, 1, -1, 0, first, second, 0);
    }
}
/* localdecomp:end func_U_003B82B8 */
