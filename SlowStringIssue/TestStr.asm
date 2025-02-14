 EUROASM CPU=X64
 EUROASM NoWarn=2101 ; W2101 Symbols was defined but never used.

TestStr PROGRAM FORMAT=DLL, MODEL=FLAT, WIDTH=64, ICONFILE=

EXPORT fnHandle
EXPORT fnString

.code

align 16
fnHandle PROC
	mov     rax, [rcx]
	mov		al, [rax + 4] ; first 4 bytes - count
	ret
ENDP fnHandle

align 16
fnString PROC
	mov		al, [rcx]
	ret
ENDP fnString

ENDPROGRAM TestStr
