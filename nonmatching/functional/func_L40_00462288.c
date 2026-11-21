/* functional: high. Decodes one UTF-8-style multibyte character from a string at *pos and advances *pos; 3-6 byte forms ignore the middle bytes exactly as retail does; invalid lead bytes return 0x3F. Compiles near-exact, only register allocation differs. */
short func_L40_00462288(unsigned char *str, int *pos) {
    int n = 0;
    unsigned int b = str[*pos];
    unsigned int v;
    unsigned int mask;
    unsigned int hi;
    unsigned int lo;
    int p;

    if (b & 0x80) {
        n = 1;
        while ((b << n) & 0x80) {
            n++;
        }
    }
    switch (n) {
    case 0:
        p = *pos;
        *pos = p + 1;
        v = str[p] & 0x7F;
        break;
    case 2:
        p = *pos;
        *pos = p + 2;
        v = ((str[p] & 0x1F) << 6) | (str[p + 1] & 0x3F);
        break;
    case 3:
        p = *pos;
        *pos = p + 3;
        v = ((str[p] & 0xF) << 12) | (str[p + 2] & 0x3F);
        break;
    case 4:
        p = *pos;
        *pos = p + 4;
        v = (((str[p] & 0xF) << 18) | (str[p + 3] & 0x3F)) & 0x1FFFFF;
        break;
    case 5:
        p = *pos;
        *pos = p + 5;
        v = (((str[p] & 0xF) << 24) | (str[p + 4] & 0x3F)) & 0x3FFFFFF;
        break;
    case 6:
        p = *pos;
        *pos = p + 6;
        v = (((str[p] & 0xF) << 30) | (str[p + 5] & 0x3F)) & 0x7FFFFFFF;
        break;
    default:
        *pos = *pos + 1;
        v = 0x3F;
        break;
    }
    return v;
}
