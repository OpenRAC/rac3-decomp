#include "common.h"

typedef struct Row_00431150 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ s16 text_id;
    /* 0x0C */ s16 mapped_key;
    /* 0x0E */ u8 pad1[0x28 - 0xE];
} Row_00431150;
typedef struct Table_00431150 {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ Row_00431150 *rows;
} Table_00431150;
typedef struct Rec_00431150 {
    /* 0x00 */ u8 pad0[0x7C];
    /* 0x7C */ s32 amount;
    /* 0x80 */ u8 pad1[0xF0 - 0x80];
} Rec_00431150;

/* localdecomp:start func_L01_00431150 */
extern Table_00431150 D_L01_001F3FA0;
extern Rec_00431150 D_L01_002C5600[];
extern u8 D_1425C0[];
extern char D_L01_001D7268[];
extern char D_L01_001D7270[];
extern u8 *func_00381FF0(s32);
extern void func_11B2E8(char *, char *, ...);

void func_L01_00431150(int index, unsigned char *output)
{
    unsigned char temporary[80];
    const unsigned char *source = func_00381FF0(D_L01_001F3FA0.rows[index].text_id);
    unsigned char *p = temporary;
    if (!source)
        return;
    while (*source && *source != '%')
        *output++ = *source++;
    if (!*source) {
        *output = *source;
        return;
    }
    ++source;
    if (*source == 'b') {
        int key = D_L01_001F3FA0.rows[index].mapped_key;
        Rec_00431150 *record = &D_L01_002C5600[D_1425C0[key]];
        func_11B2E8((char *)temporary, D_L01_001D7268, record->amount);
    } else {
        func_11B2E8((char *)temporary, D_L01_001D7270);
    }
    ++source;
    while (*p)
        *output++ = *p++;
    while (*source)
        *output++ = *source++;
    *output = 0;
}
/* localdecomp:end func_L01_00431150 */

/* localdecomp:start func_L01_004312D8 */
__asm__(".extern D_001D545C, 16");
extern int D_001D545C;
extern int D_L01_002F14B0[];
extern int D_L01_001EFE20[];

/* from rac2-decomp's func_L00_00309140 */
void func_L01_004312D8(int a, int b) {
    int i = D_001D545C;
    if (i < 19) {
        b += D_L01_002F14B0[i];
        D_L01_001EFE20[b] = a;
    }
}
/* localdecomp:end func_L01_004312D8 */
