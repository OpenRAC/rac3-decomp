/* functional: high. Near miss of 21 register-only diffs: same instruction stream and store order, only register allocation differs. */
/* localdecomp:start func_L01_003FE938 */
extern s32 D_L01_001DF948;
extern s32 D_L01_001EA940[];
extern s32 D_L01_001E1070;
extern s32 D_001E1070_sda;
__asm__(".extern D_001E1070_sda, 4");
typedef struct { s32 start,end,limit,records,count,extra,result; } State_003FE938;
extern s32 D_L01_001E64C0[];
extern s32 D_L01_001D66A4;
extern s32 D_001D4BB4;
extern f32 D_L01_001DF950;
void func_L01_003FE938(void) {
 extern void func_003A92F0(s32);
 extern void func_0012C908(s32);
 extern void func_003A9108(void);
 extern void func_003A5430(void);
 State_003FE938 *p;
 func_003A92F0(1);
 func_0012C908(0);

 p = (State_003FE938 *)D_L01_001E64C0;
 D_L01_001DF948++;
 p->extra = D_L01_001E1070 - 0x60000;
 p->start = D_L01_001EA940[3] + 0x60000;
 p->end = D_L01_001EA940[4] + 0x60000;
 p->limit = p->start + 0xD0800;
 D_L01_001D66A4 = 0x2000;
 D_001E1070_sda = 0x60000;
 func_003A9108();
 func_003A5430();
 p->result = D_001D4BB4;
 D_L01_001DF950 = 1.0f;
}
/* localdecomp:end func_L01_003FE938 */
