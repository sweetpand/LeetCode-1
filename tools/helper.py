def get_directory(lang: str, problemID: str, extension: str) -> str:
    return './solutions/' + lang + '/' + problemID + extension


def get_mkdocs_path_name(i: int) -> str:
    return str(i + 1).zfill(4) + '-' + str(i + 100).zfill(4)


def get_mkdocs_file_name(i: int) -> str:
    return str(i + 1).zfill(4) + '-' + str(i + 10).zfill(4) + '.md'
