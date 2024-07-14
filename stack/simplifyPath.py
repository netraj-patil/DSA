class Solution:
    def simplifyPath(self, path: str) -> str:
        if path == '':
            return ''
        lis = path.split('/')
        dir = []
        for ch in lis:
            if ch == '.':
                continue
            if ch == '..':
                if dir:
                    dir.pop()
                continue
            if ch == '':
                continue
            dir.append(ch)
        
        if not dir:
            return '/'
        
        str = ''
        for item in dir:
            str += f'/{item}'
        return str