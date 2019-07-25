namespace nm21
{
	class CA
	{
	public:
		void nFun()
		{
		}
		virtual void vFun()
		{
		}
	};
	void main()
	{
		CA obj;
		CA & objRef = obj;
		CA *objPtr = &obj;

		obj.nFun();
		obj.vFun();
		objRef.nFun();
		objPtr->nFun();
		/*
	; Line 18
		lea	ecx, DWORD PTR _obj$[ebp]
		call	?nFun@CA@@QAEXXZ			; CA::nFun
	; Line 19
		lea	ecx, DWORD PTR _obj$[ebp]
		call	?vFun@CA@@UAEXXZ			; CA::vFun
	; Line 20
		mov	ecx, DWORD PTR _objRef$[ebp]
		call	?nFun@CA@@QAEXXZ			; CA::nFun
	; Line 21
		mov	ecx, DWORD PTR _objPtr$[ebp]
		call	?nFun@CA@@QAEXXZ			; CA::nFun

		*/

		objRef.vFun();//objRef.vptr->vtable[0]()
		objPtr->vFun();//objPtr->vptr->vtable[0]()
		/*
	; Line 38
		mov	eax, DWORD PTR _objRef$[ebp]
		mov	edx, DWORD PTR [eax]
		mov	esi, esp
		mov	ecx, DWORD PTR _objRef$[ebp]
		mov	eax, DWORD PTR [edx]
		call	eax
		cmp	esi, esp
		call	__RTC_CheckEsp
	; Line 39
		mov	eax, DWORD PTR _objPtr$[ebp]
		mov	edx, DWORD PTR [eax]
		mov	esi, esp
		mov	ecx, DWORD PTR _objPtr$[ebp]
		mov	eax, DWORD PTR [edx]
		call	eax
		cmp	esi, esp
		call	__RTC_CheckEsp

		*/

	}
}