verts = #([0,0,0],[10,0,0],[0,10,0],[10,10,0])		-- vertex 배열
facs= #([1,2,3],[2,4,3])				-- face 배열
tvertexs = #([0,0,0],[1,0,0],[0,1,0],[1,1,0])		-- 텍스쳐 vertex 좌표 배열
obj = mesh vertices:verts  faces:facs  tverts:tvertexs	-- mesh 생성
buildTVFaces obj					--  TVFace 배열을 생성
for i = 1 to obj.numfaces do 
(
	face = getFace obj i		-- face를 이루는 vertex 조합을 알아낸다
	setTVFace obj i face		-- TVFace에 텍스쳐를 입힌다
)

st = StandardMaterial  showInViewport:true		-- Standard Material 적용
st.diffusemap = checker()			-- checker 맵을 st 디퓨즈에 넣는다
obj.material = st				-- 오브젝트에 메터리얼 적용
