import subprocess

GET_PROFILES_COMMAND = "netsh wlan show profiles"
GET_PASSWORD_COMMAND = "netsh wlan show profiles \"{0}\" key=clear"
ENCODING = "UTF-8"

def run(command : str) -> str:
    return subprocess.check_output(command).decode(ENCODING)

def remove_all_text_before(origin_text : str, anchor : str) -> str:
    ignore_pos = origin_text.find(anchor)
    text = origin_text[ignore_pos:]

    return text


def get_wifi_name_list(profiles_output : str) -> list[str]:
    PROFILE_LABEL = "All User Profile"
    profiles_output = remove_all_text_before(profiles_output, PROFILE_LABEL)

    SPLIT_CHAR = "\n"
    profiles_output_splitted = profiles_output.split(SPLIT_CHAR)

    AMOUNT_CHARS_IGNORED = 2
    wifi_name_list = list[str]()
    for line in profiles_output_splitted:
        if PROFILE_LABEL in line:
            beginning_wifi_name_pos = line.find(":") + AMOUNT_CHARS_IGNORED
            wifi_name_list.append(line[beginning_wifi_name_pos:].strip())

    return wifi_name_list

def get_password(wifi_name : str) -> str:
    password_content = run(GET_PASSWORD_COMMAND.format(wifi_name))

    PASSWORD_LABEL = "Key Content"
    if PASSWORD_LABEL not in password_content:
        return "Password can't be found!"

    END_OF_LINE_CHAR = "\n"
    AMOUNT_CHARS_IGNORED = 2
    PASSWORD_LABEL_POS = password_content.find(PASSWORD_LABEL)
    BEGINNING_PASSWORD_POS = password_content.find(":", PASSWORD_LABEL_POS) + AMOUNT_CHARS_IGNORED
    END_OF_LINE_POS = password_content.find(END_OF_LINE_CHAR, BEGINNING_PASSWORD_POS)

    return password_content[BEGINNING_PASSWORD_POS:END_OF_LINE_POS]
    

if __name__ == "__main__":
    profiles_output = run(GET_PROFILES_COMMAND)
    wifi_name_list = get_wifi_name_list(profiles_output)

    for wifi_name in wifi_name_list:
        print("(!) Wifi: {0}".format(wifi_name))
        print("    Password: {0}\n".format(get_password(wifi_name)))
