mapname = "C:\\Program Files\\Autodesk\\3ds Max 2008\\maps\\ELMLEAF.TGA"
map = openbitmap mapname		-- ��Ʈ���� ���� �Ѵ�

rollout test "hello world~" 
(
)
createdialog test width:512 height:512   \
	bitmap:map   bmpstyle:#bmp_stretch