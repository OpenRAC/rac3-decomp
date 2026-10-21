/* Near miss of func_003E9828 with its file's own flags: tools/check.py reports 507 diff
   (the version it replaces: 522).
   What differs: The six argument globals (D_001D9700/9730/9760/9790/97C0/97F0) and the six
   address-taken tables (D_001DA948/968/988/9A8/9C8/9E8) are now reached with lui/lo like
   retail (declared as unsized arrays under per-function alias names), but (1) retail rebuilds
   each global address at every use with the high half in the load's destination register (`lui
   $a1, %hi(D); lw $a1, %lo(D)($a1)`), while gcc's split-address form folds the high half into
   one CSE'd pseudo kept in $s0..$s3, which pushes the table-address pseudos out of the $s
   registers retail uses ($s0=D_31B8A0 ... $fp=D_31B858); with one alias...
*/

/* US draft of func_003E9828 (rac3-uya-decomp func_003E96C8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003E9828 */
__asm__(".extern D_001D96BC, 1");
extern u8 D_001D96BC;
/* Retail reaches these globals through lui/lw, not $gp: declare them as
   unsized arrays (never small data) under a per-function alias name. */
extern s32 D_001D9700_003E9828[];
extern s32 D_001D9730_003E9828[];
extern s32 D_001D9760_003E9828[];
extern s32 D_001D9790_003E9828[];
extern s32 D_001D97C0_003E9828[];
extern s32 D_001D97F0_003E9828[];
extern s32 D_001DA948_003E9828[];
extern s32 D_001DA968_003E9828b[];
extern s32 D_001DA988_003E9828[];
extern s32 D_001DA9A8_003E9828[];
extern s32 D_001DA9C8_003E9828[];
extern s32 D_001DA9E8_003E9828b[];
extern s32 D_001D9700;
extern s32 D_001D9730;
extern s32 D_001D9760;
extern s32 D_001D9790;
extern s32 D_001D97C0;
extern s32 D_001D97F0;
extern s32 D_001DA948[2];
extern s32 D_001DA968_003E9828[2];
extern s32 D_001DA988[2];
extern s32 D_001DA9A8[2];
extern s32 D_001DA9C8[2];
extern s32 D_001DA9E8_003E9828[2];
extern u8 D_0031B7C8[];
extern u8 D_0031B810[];
extern u8 D_0031B858[];
extern u8 D_0031B8A0[];
extern u8 D_0031B8E8[];
extern u8 D_0031B930[];
extern u8 D_0031B978[];
extern u8 D_0031B9C0[];
extern u8 D_0031BA08[];
extern u8 D_0031BA50[];
extern u8 D_0031BA98[];
extern u8 D_0031BAE0[];
extern u8 D_0031BB28[];
extern u8 D_0031BB70[];
extern u8 D_0031BBB8[];
extern u8 D_0031BC00[];
extern u8 D_0031BC48[];
extern u8 D_0031BC90[];
extern u8 D_0031BCD8[];
extern u8 D_0031BD20[];
extern u8 D_0031BD68[];
extern u8 D_0031BDB0[];
extern s32 func_003EAD00_003E9828(void *, s32, void *);
extern s32 func_003EAE38_003E9828(void *, s32, void *);
extern s32 func_003EAF58_003E9828(void *, s32, void *);
extern s32 func_003EB0E0_003E9828(void *, s32, void *);
extern s32 func_003EB218_003E9828(void *, s32, void *);
extern s32 func_003EB350_003E9828(void *, s32, void *);
extern s32 func_003EB4F0_003E9828(void *, s32, void *);
extern s32 func_003EB700_003E9828(void *, s32, void *);
extern s32 func_003EB820_003E9828(void *, s32, void *);
extern s32 func_003EBAB8_003E9828(void *, s32, void *);
extern s32 func_003EBFA0_003E9828(void *, s32, void *);
extern s32 func_003EC0D8(void *, s32, void *);
extern s32 func_003EC2D8_003E9828(void *, s32, void *);
extern s32 func_003EC9D0_003E9828(void *, s32, void *);
extern s32 func_003ECAF8_003E9828(void *, s32, void *);
extern s32 func_003ED280_003E9828(void *, s32, void *);
extern s32 func_003ED718_003E9828(void *, s32, void *);
extern s32 func_003ED890_003E9828(void *, s32, void *);
extern s32 func_003EAC98(u8 *p, f32 a, f32 b);
extern s32 func_003EADD0(u8 *p, s32 a, s32 b);
extern s32 func_003EAF08(u8 *p, s32 a);
extern s32 func_003EB028(u8 *p, f32 a, f32 b);
extern s32 func_003EB090(u8 *p, s32 a);
extern s32 func_003EB1B0(u8 *p, s32 a, s32 b);
extern s32 func_003EB2E8(u8 *p, s32 a, u8 *out);
extern s32 func_003EB420(u8 *p, s32 a, s32 b);
extern s32 func_003EB488(u8 *p, s32 a, s32 b);
extern s32 func_003EB5C0(u8 *p, f32 a, f32 b);
extern s32 func_003EB628(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EB7D0(u8 *p, s32 a);
extern s32 func_003EB8F8(u8 *p, f32 a, f32 b);
extern s32 func_003EB968(u8 *p, s32 a, s32 b);
extern s32 func_003EB9D0(u8 *p, s32 a);
extern s32 func_003EBA28(u8 *p, s32 a, s16 b, s16 c, s32 d);
extern s32 func_003EBB88(u8 *p, f32 a, f32 b);
extern s32 func_003EBBF8(u8 *p, s32 a);
extern s32 func_003EBC50(u8 *p, s32 a, s32 b);
extern s32 func_003EBCB8(u8 *p, s32 a, u8 *out);
extern s32 func_003EBD20(u8 *p, s32 a, s32 b);
extern s32 func_003EBD88(u8 *p, s32 a, s32 b);
extern s32 func_003EBDF0(u8 *p, f32 a, f32 b);
extern s32 func_003EBE58(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EBF30(u8 *p, f32 a, f32 b);
extern s32 func_003EC078(u8 *p, f32 a);
extern s32 func_003EC1B0(u8 *p, f32 a);
extern s32 func_003EC210(u8 *p, f32 a, f32 b);
extern s32 func_003EC280(u8 *p, s32 a);
extern s32 func_003EC3A8(u8 *p, s32 a, s32 b);
extern s32 func_003EC410(u8 *p, s32 a);
extern s32 func_003EC468(u8 *p, f32 a, f32 b);
extern s32 func_003EC4D0(u8 *p, s32 a, s32 b);
extern s32 func_003EC538(u8 *p, f32 a, f32 b);
extern s32 func_003EC5A0();
extern s32 func_003EC608();
extern s32 func_003EC668(u8 *p, s32 a, s32 b);
extern s32 func_003EC6D0(u8 *p, s32 a, u8 *out);
extern s32 func_003EC738(u8 *p, s32 a, s32 b);
extern s32 func_003EC7A0(u8 *p, s32 a, s32 b);
extern s32 func_003EC808(u8 *p, f32 a, f32 b);
extern s32 func_003EC870(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EC948(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_003ECAA0(u8 *p, f32 a);
extern s32 func_003ECBC8(u8 *p, f32 a, f32 b);
extern s32 func_003ECC30(u8 *p, s32 a, s32 b);
extern s32 func_003ECC98(u8 *p, f32 a, f32 b);
extern s32 func_003ECD00(u8 *p, s32 a);
extern s32 func_003ECD50(u8 *p, s32 a, s32 b);
extern s32 func_003ECDB8(u8 *p, s32 a, u8 *out);
extern s32 func_003ECE20(u8 *p, s32 a, s32 b);
extern s32 func_003ECE88(u8 *p, s32 a, s32 b);
extern s32 func_003ECEF0(u8 *p, f32 a, f32 b);
extern s32 func_003ECF58(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ED030(u8 *p, f32 a, f32 b);
extern s32 func_003ED098(u8 *p, f32 a, f32 b);
extern s32 func_003ED100(u8 *p, s32 a, s32 b);
extern s32 func_003ED168(u8 *p, f32 a, f32 b);
extern s32 func_003ED1D0(u8 *p, s32 a);
extern s32 func_003ED220();
extern s32 func_003ED350(u8 *p, s32 a, s32 b);
extern s32 func_003ED3B8(u8 *p, s32 a, u8 *out);
extern s32 func_003ED420(u8 *p, s32 a, s32 b);
extern s32 func_003ED488(u8 *p, s32 a, s32 b);
extern s32 func_003ED4F0(u8 *p, f32 a, f32 b);
extern s32 func_003ED558(u8 *p, f32 a);
extern s32 func_003ED5B0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ED688(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 func_003ED7E8();
extern s32 func_003ED840();
extern s32 func_003ED960(u8 *p, s32 a, s32 b);
extern s32 func_003ED9C8(u8 *p, s32 a, u8 *out);
extern s32 func_003EDA30(u8 *p, s32 a, s32 b);
extern s32 func_003EDA98(u8 *p, s32 a, s32 b);
extern s32 func_003EDB00(u8 *p, f32 a, f32 b);
extern s32 func_003EDB68(u8 *p, f32 a, f32 b);
extern s32 func_003EDBD8(u8 *p, s32 a, s32 b);
extern s32 func_003EDC40(u8 *p, f32 a, f32 b);

s32 func_003E9828(void) {
    if (D_001D96BC == 0) {
        D_001D96BC = 1;
        func_003EAD00_003E9828(D_0031B7C8, D_001D9790_003E9828[0], func_003EAC98);
        func_003EAE38_003E9828(D_0031B810, D_001D9790_003E9828[0], func_003EADD0);
        func_003EAF58_003E9828(D_0031B8A0, D_001D9790_003E9828[0], func_003EAF08);
        func_003EAD00_003E9828(D_0031B858, D_001D9790_003E9828[0], func_003EB028);
        func_003EB0E0_003E9828(D_0031B930, D_001D9790_003E9828[0], func_003EB090);
        func_003EB218_003E9828(D_0031BC00, D_001D9790_003E9828[0], func_003EB1B0);
        func_003EB350_003E9828(D_0031BC48, D_001D9790_003E9828[0], func_003EB2E8);
        func_003EB218_003E9828(D_0031BC90, D_001D9790_003E9828[0], func_003EB420);
        func_003EB4F0_003E9828(D_0031BCD8, D_001D9790_003E9828[0], func_003EB488);
        func_003EAD00_003E9828(D_0031B978, D_001D9790_003E9828[0], func_003EB5C0);
        func_003EB700_003E9828(D_0031BD20, D_001D9790_003E9828[0], func_003EB628);
        func_003EB820_003E9828(D_001DA9E8_003E9828b, D_001D9790_003E9828[0], func_003EB7D0);
        func_003EAD00_003E9828(D_0031B7C8, D_001D97C0_003E9828[0], func_003EB8F8);
        func_003EAE38_003E9828(D_0031B810, D_001D97C0_003E9828[0], func_003EB968);
        func_003EAF58_003E9828(D_0031B8A0, D_001D97C0_003E9828[0], func_003EB9D0);
        func_003EBAB8_003E9828(D_0031B8E8, D_001D97C0_003E9828[0], func_003EBA28);
        func_003EAD00_003E9828(D_0031B858, D_001D97C0_003E9828[0], func_003EBB88);
        func_003EB0E0_003E9828(D_0031B930, D_001D97C0_003E9828[0], func_003EBBF8);
        func_003EB218_003E9828(D_0031BC00, D_001D97C0_003E9828[0], func_003EBC50);
        func_003EB350_003E9828(D_0031BC48, D_001D97C0_003E9828[0], func_003EBCB8);
        func_003EB218_003E9828(D_0031BC90, D_001D97C0_003E9828[0], func_003EBD20);
        func_003EB4F0_003E9828(D_0031BCD8, D_001D97C0_003E9828[0], func_003EBD88);
        func_003EAD00_003E9828(D_0031B978, D_001D97C0_003E9828[0], func_003EBDF0);
        func_003EB700_003E9828(D_0031BD20, D_001D97C0_003E9828[0], func_003EBE58);
        func_003EBFA0_003E9828(D_001DA948_003E9828, D_001D97C0_003E9828[0], func_003EBF30);
        func_003EC0D8(D_001DA968_003E9828b, D_001D97C0_003E9828[0], func_003EC078);
        func_003EC0D8(D_001DA988_003E9828, D_001D97C0_003E9828[0], func_003EC1B0);
        func_003EBFA0_003E9828(D_001DA9A8_003E9828, D_001D97C0_003E9828[0], func_003EC210);
        func_003EC2D8_003E9828(D_0031B9C0, D_001D97C0_003E9828[0], func_003EC280);
        func_003EAE38_003E9828(D_0031BA08, D_001D97C0_003E9828[0], func_003EC3A8);
        func_003EB820_003E9828(D_001DA9E8_003E9828b, D_001D97C0_003E9828[0], func_003EC410);
        func_003EAD00_003E9828(D_0031B7C8, D_001D9760_003E9828[0], func_003EC468);
        func_003EAE38_003E9828(D_0031B810, D_001D9760_003E9828[0], func_003EC4D0);
        func_003EAD00_003E9828(D_0031B858, D_001D9760_003E9828[0], func_003EC538);
        func_003EB0E0_003E9828(D_0031B930, D_001D9760_003E9828[0], func_003EC5A0);
        func_003EB0E0_003E9828(D_0031BA50, D_001D9760_003E9828[0], func_003EC608);
        func_003EB218_003E9828(D_0031BC00, D_001D9760_003E9828[0], func_003EC668);
        func_003EB350_003E9828(D_0031BC48, D_001D9760_003E9828[0], func_003EC6D0);
        func_003EB218_003E9828(D_0031BC90, D_001D9760_003E9828[0], func_003EC738);
        func_003EB4F0_003E9828(D_0031BCD8, D_001D9760_003E9828[0], func_003EC7A0);
        func_003EAD00_003E9828(D_0031B978, D_001D9760_003E9828[0], func_003EC808);
        func_003EB700_003E9828(D_0031BD20, D_001D9760_003E9828[0], func_003EC870);
        func_003EC9D0_003E9828(D_0031BD68, D_001D9760_003E9828[0], func_003EC948);
        func_003ECAF8_003E9828(D_0031BDB0, D_001D9760_003E9828[0], func_003ECAA0);
        func_003EAD00_003E9828(D_0031B7C8, D_001D9730_003E9828[0], func_003ECBC8);
        func_003EAE38_003E9828(D_0031B810, D_001D9730_003E9828[0], func_003ECC30);
        func_003EAD00_003E9828(D_0031B858, D_001D9730_003E9828[0], func_003ECC98);
        func_003EB0E0_003E9828(D_0031B930, D_001D9730_003E9828[0], func_003ECD00);
        func_003EB218_003E9828(D_0031BC00, D_001D9730_003E9828[0], func_003ECD50);
        func_003EB350_003E9828(D_0031BC48, D_001D9730_003E9828[0], func_003ECDB8);
        func_003EB218_003E9828(D_0031BC90, D_001D9730_003E9828[0], func_003ECE20);
        func_003EB4F0_003E9828(D_0031BCD8, D_001D9730_003E9828[0], func_003ECE88);
        func_003EAD00_003E9828(D_0031B978, D_001D9730_003E9828[0], func_003ECEF0);
        func_003EB700_003E9828(D_0031BD20, D_001D9730_003E9828[0], func_003ECF58);
        func_003EBFA0_003E9828(D_001DA9C8_003E9828, D_001D9730_003E9828[0], func_003ED030);
        func_003EAD00_003E9828(D_0031B7C8, D_001D97F0_003E9828[0], func_003ED098);
        func_003EAE38_003E9828(D_0031B810, D_001D97F0_003E9828[0], func_003ED100);
        func_003EAD00_003E9828(D_0031B858, D_001D97F0_003E9828[0], func_003ED168);
        func_003EB0E0_003E9828(D_0031B930, D_001D97F0_003E9828[0], func_003ED1D0);
        func_003ED280_003E9828(D_0031BB70, D_001D97F0_003E9828[0], func_003ED220);
        func_003EB218_003E9828(D_0031BC00, D_001D97F0_003E9828[0], func_003ED350);
        func_003EB350_003E9828(D_0031BC48, D_001D97F0_003E9828[0], func_003ED3B8);
        func_003EB218_003E9828(D_0031BC90, D_001D97F0_003E9828[0], func_003ED420);
        func_003EB4F0_003E9828(D_0031BCD8, D_001D97F0_003E9828[0], func_003ED488);
        func_003EAD00_003E9828(D_0031B978, D_001D97F0_003E9828[0], func_003ED4F0);
        func_003ECAF8_003E9828(D_0031BBB8, D_001D97F0_003E9828[0], func_003ED558);
        func_003EB700_003E9828(D_0031BD20, D_001D97F0_003E9828[0], func_003ED5B0);
        func_003ED718_003E9828(D_0031BB28, D_001D9700_003E9828[0], func_003ED688);
        func_003EB0E0_003E9828(D_0031BA98, D_001D9700_003E9828[0], func_003ED7E8);
        func_003ED890_003E9828(D_0031BAE0, D_001D9700_003E9828[0], func_003ED840);
        func_003EB218_003E9828(D_0031BC00, D_001D9700_003E9828[0], func_003ED960);
        func_003EB350_003E9828(D_0031BC48, D_001D9700_003E9828[0], func_003ED9C8);
        func_003EB218_003E9828(D_0031BC90, D_001D9700_003E9828[0], func_003EDA30);
        func_003EB4F0_003E9828(D_0031BCD8, D_001D9700_003E9828[0], func_003EDA98);
        func_003EAD00_003E9828(D_0031B978, D_001D9700_003E9828[0], func_003EDB00);
        func_003EAD00_003E9828(D_0031B7C8, D_001D9700_003E9828[0], func_003EDB68);
        func_003EAE38_003E9828(D_0031B810, D_001D9700_003E9828[0], func_003EDBD8);
        func_003EAD00_003E9828(D_0031B858, D_001D9700_003E9828[0], func_003EDC40);
    }
    return 1;
}
/* localdecomp:end func_003E9828 */
