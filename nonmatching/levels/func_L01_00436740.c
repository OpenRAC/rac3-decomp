/* func_L01_00436740: near miss (w3 p2w2). MATCH at home level 01 and 3 others (with file @ps2as flags), 34 places.
   False fold: other levels call other callback addresses (e.g. level_29: 0x476d20 vs 0x436568), levels differ.
   Twin func_0029CD48 (rac2); offsets 0x84, 0x24F10, 0x4DCC. */
extern char D_L01_001EA940[];
extern int D_001CD0C0[];
extern int D_001D545C;
extern int D_00143950[];
extern char *D_L01_001D67C8;
extern void *func_0011A264(void *, int, int);
extern void func_L01_00436718(int);
extern int *func_L01_00521C90(int, int);
extern char *func_003AF0B8(int *, int);
extern void func_L01_00436568(void);
extern void func_L01_004365A0(void);
extern void func_L01_00436570(void);
extern void func_L01_00436710(void);
typedef struct { char pad[0x4DCC]; void *cb1; void *cb2; } SubBf;

void func_L01_00436740(void)
{
    char *state = D_L01_001EA940;
    char *obj;
    func_0011A264(*(void **)(state + 0x84), 0xCD, 0x40000);
    D_001CD0C0[104] = 0;
    D_001CD0C0[105] = 0;
    D_001CD0C0[106] = 0;
    D_001CD0C0[107] = 0;
    D_001CD0C0[108] = 0;
    D_001CD0C0[109] = 0;
    D_001CD0C0[110] = 0;
    D_001CD0C0[111] = 0;
    D_001CD0C0[112] = 0;
    D_001CD0C0[113] = 0;
    D_001CD0C0[114] = 0;
    D_001CD0C0[115] = 0;
    func_L01_00436718(D_00143950[0]);
    obj = func_003AF0B8(func_L01_00521C90(0x24F10, *(int *)(state + 0x84)), 0x40000);
    D_L01_001D67C8 = obj;
    if (D_001D545C == 0x1F5) {
        ((SubBf *)(obj + 0x20000))->cb1 = func_L01_00436568;
        ((SubBf *)(obj + 0x20000))->cb2 = func_L01_00436710;
    } else {
        ((SubBf *)(obj + 0x20000))->cb1 = func_L01_004365A0;
        ((SubBf *)(obj + 0x20000))->cb2 = func_L01_00436570;
    }
}