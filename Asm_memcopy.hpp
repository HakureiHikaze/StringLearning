#ifndef STRINGLEARNING_ASM_MEMCOPY_HPP
#define STRINGLEARNING_ASM_MEMCOPY_HPP
#ifdef __cplusplus
extern "C"
#endif
void *(* memcopy)( void *dest , void *src , size_t n );

void *memcopy_dword(void *dest, void *src, size_t n)
{
    __asm volatile(
        "mov esi, src"
        "mov edi, dest"
        "mov ecx, n"
        "mov ebx, ecx"
        "and ecx, 3"
        "rep movsb"
        "mov ecx, ebx"
        "shr ecx, 2"
        "rep movsd"
        );

    return dest;
}
#endif //STRINGLEARNING_ASM_MEMCOPY_HPP

/*
 * Author: Jerry Cat
 * Date: 2006/04/27
 * url: http://www.cppblog.com/jerysun0818/archive/2006/04/27/6392.html
*/
