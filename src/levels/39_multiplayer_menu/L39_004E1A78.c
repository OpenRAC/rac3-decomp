#include "common.h"

/* localdecomp:start func_L39_004E1A78 */
extern char D_L39_00477328[];
extern char D_L39_00477338[];
extern char D_L39_00477348[];
extern void func_L39_004DE868(void *);
extern s32 func_00120B70(char *, char *, s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004DEB50(char *);
extern s32 func_L01_004CC758(void *);
extern s32 func_L39_004E1CB8(char **, char *, s32);
extern s32 func_L39_004DE650(void *, void *, s32, char *);

s32 func_L39_004E1A78(char *header, void *cipher) {
    char iv[32];
    void *enc;
    char *p;
    char c;

    func_L39_004DE868(cipher);
    if (header == 0 || *header == 0 || *header == '\n') {
        return 1;
    }
    if (func_00120B70(header, D_L39_00477328, 11) != 0) {
        func_L39_004BC6C8(9, 0x76, 0x6B, 0, 0);
        return 0;
    }
    header += 11;
    if (*header != '4') return 0;
    header++;
    if (*header != ',') return 0;
    header++;
    if (func_00120B70(header, D_L39_00477338, 9) != 0) {
        func_L39_004BC6C8(9, 0x76, 0x6A, 0, 0);
        return 0;
    }
    for (; *header != '\n' && *header != 0; header++) {}
    if (*header == 0) {
        func_L39_004BC6C8(9, 0x76, 0x70, 0, 0);
        return 0;
    }
    header++;
    if (func_00120B70(header, D_L39_00477348, 10) != 0) {
        func_L39_004BC6C8(9, 0x76, 0x69, 0, 0);
        return 0;
    }
    header += 10;
    p = header;
    for (;;) {
        c = *header;
        if (!((c >= 'A' && c <= 'Z') || c == '-' || (c >= '0' && c <= '9'))) break;
        header++;
    }
    *header = 0;
    enc = func_L39_004DEB50(p);
    *header = c;
    header++;
    if (enc == 0) {
        func_L39_004BC6C8(9, 0x76, 0x72, 0, 0);
        return 0;
    }
    if (!func_L39_004E1CB8(&header, iv, func_L01_004CC758(enc))) return 0;
    return func_L39_004DE650(cipher, enc, 0, iv);
}
/* localdecomp:end func_L39_004E1A78 */
