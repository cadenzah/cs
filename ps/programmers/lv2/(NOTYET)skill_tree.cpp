// stack
// 문자열을 뒤에서부터 앞으로 보면서,
// skill.top()과 일치하는걸 만나면, skill.pop()
  // 문자열 다 돌기 전까지 skill.empty()가 true되면 성공 - 아니면 실패
// 문자열 다 돌고나서, skill.pop()이 한번도 안 일어났으면,
  // skill.pop()한 뒤 다시 수행
  // 만약에 이런식으로 skill이 다 비어져버리면, 성공으로 간주 (스킬트리 미사용)
