mapname = "C:\\Program Files\\Autodesk\\3ds Max 2008\\maps\\ELMLEAF.TGA"
map = openbitmap mapname		-- ºñÆ®¸ÊÀ» ¿ÀÇÂ ÇÑ´Ù

rollout test "hello world~" 
(
)
createdialog test width:512 height:512   \
	bitmap:map   bmpstyle:#bmp_stretch