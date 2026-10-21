#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C7C38();
extern void func_003C7DD8();
extern s32 func_003C7310();
extern void func_003C7480();
extern void func_003C7958();
extern void func_003C6FE0();
extern void func_003CA4A0();
extern void func_003CB050();
extern void func_003CB300();
extern void *func_003CB3E0(s32, void *, s32, s32);
extern void func_003C8B18();
extern void func_003C6FB0(s32, s32 *, s32 *, s32 *);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/handwritten", func_003C6FB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C6FE0);

ASM_FUNC("asm/handwritten", func_003C7310);

ASM_FUNC("asm/handwritten", func_003C7480);

ASM_FUNC("asm/handwritten", func_003C7550);

ASM_FUNC("asm/handwritten", func_003C7710);

ASM_FUNC("asm/handwritten", func_003C7880);

ASM_FUNC("asm/handwritten", func_003C78E0);

ASM_FUNC("asm/handwritten", func_003C7958);

ASM_FUNC("asm/handwritten", func_003C7C38);

INCLUDE_ASM("asm/nonmatchings/text", func_003C7DD4);

ASM_FUNC("asm/handwritten", func_003C7DD8);

ASM_FUNC("asm/handwritten", func_003C7E20);

ASM_FUNC("asm/handwritten", func_003C8B18);

ASM_FUNC("asm/handwritten", func_003C97F0);

ASM_FUNC("asm/handwritten", func_003CA4A0);

ASM_FUNC("asm/handwritten", func_003CA608);

ASM_FUNC("asm/handwritten", func_003CB050);

ASM_FUNC("asm/handwritten", func_003CB300);

ASM_FUNC("asm/handwritten", func_003CB3E0);

ASM_FUNC("asm/handwritten", func_003CCE20);
