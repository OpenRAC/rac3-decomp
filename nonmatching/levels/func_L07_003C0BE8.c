/* Resolved in the third retry on 2026-11-15: integrated in L07_003C0710.c.
   Full PAL level build MATCH (15 to 0) reading the flag as D_001D5530[0xD]
   from an unsized section(".sdata") table. Retained as historical evidence. */
/* Level 7 near miss: 15 differences, all from one delay-slot choice at the
   D_001426E0[0x91] beqz. Retail puts daddu $4,$17,$0 in the slot and the
   lui after the branch; this C puts the lui in the slot, which cascades through
   the following bnez slot, the f(obj,2,-1) junction and one lbu register.
   Registered class (level 2 one-instruction shift, func_L02_00313B38). Not
   linked; owning flags unchanged. No VU0. */
typedef struct {
    u8 pad0[8];
    s32 f8;
    u8 padC[0x10];
    s32 f1C;
} P_003C0BE8;

extern u8 *D_001DE550_sda;
__asm__(".extern D_001DE550_sda, 4");
extern char *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern u8 D_001426E0[];
extern u8 D_00142CBE[];
extern s32 D_00142C30[];
extern u8 D_001D553D[];

extern void func_L01_0042B068(s32, s32);
extern void func_L01_0045F1E8(s32, s32);
extern void func_L01_00456230(char *, s32);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L07_003C1E48(u8 *);
extern void func_L07_003C1E80(u8 *);

void func_L07_003C0BE8(u8 *obj) {
    P_003C0BE8 *p68;
    char *p;

    func_L01_0042B068(1, 0);
    p68 = *(P_003C0BE8 **)(obj + 0x68);
    D_001DE550_sda = obj;
    func_L01_0045F1E8(p68->f1C, -1);

    if ((D_00142C30[0] & 0x10000) == 0) {
        p = D_L07_001DF41C + (p68->f8 << 8);
        func_L01_00456230(p, 1);
        (*(void (**)(char *))(p + 0x64))(p);
        func_L01_004450F0((s32)obj, 0xA, -1);
        return;
    }
    if (D_001426E0[0x8F] != 0 && D_00142CBE[0] == 0) {
        func_L07_003C1E48(obj);
        func_L01_004450F0((s32)obj, 1, -1);
        return;
    }
    if (D_001426E0[0x91] != 0 && D_001D553D[0] == 0) {
        func_L07_003C1E80(obj);
        func_L01_004450F0((s32)obj, 1, -1);
        return;
    }
    func_L01_004450F0((s32)obj, 2, -1);
}
