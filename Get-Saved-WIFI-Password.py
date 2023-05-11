import os
import subprocess

def clrscr():
    """This function is used to clear terminal screen"""
    os.system("cls")

GET_PROFILES_COMMAND = "netsh wlan show profiles"
GET_PASSWORD_COMMAND = 'netsh wlan show profiles "{0}" key=clear'

def commandOutput(command):
    """Get output when run command in terminal"""
    output = subprocess.check_output(command)
    return output.decode('utf-8')

def getProfiles():
    """Get all wifi profiles"""
    return commandOutput(GET_PROFILES_COMMAND)

def getRangeOfWifiName(profiles):
    """Get the range of the wifi name"""
    firstCharacterPosition = profiles.find('All User Profile')
    firstCharacterPosition = profiles.find(':', firstCharacterPosition)
    firstCharacterPosition += 2

    lastCharacterPosition = profiles.find('\r', firstCharacterPosition)

    return [firstCharacterPosition, lastCharacterPosition]

def getWifiName(profiles):
    """Return fisrt wifi name in profile"""
    fisrt, last = getRangeOfWifiName(profiles)
    return profiles[fisrt:last]

def getPassword(wifiName):
    """Return password of wifi"""
    result = commandOutput(GET_PASSWORD_COMMAND.format(wifiName))
    start = result.find('Key Content')
    if start == -1:
        return "This WIFI seems not to have the password!"
    end = result.find('\n', start)
    return result[start:end].replace('Key Content', 'Password')

def removeWifiNameInProfiles(wifiName, profiles):
    """Remove first wifi whose name match"""
    LENGHT_OF_LABEL = 27
    LENGHT_OF_LAST_CONTROL_CHARACTER = 2
    startPos = profiles.find(wifiName)
    startPos -= LENGHT_OF_LABEL

    endPos = startPos + LENGHT_OF_LABEL + len(wifiName) + LENGHT_OF_LAST_CONTROL_CHARACTER

    return profiles[:startPos] + profiles[endPos:]

def printBanner():
    """This function is used to print the banner of the program"""
    print("-----------------------------------------")
    print(" TOOL TO FIND YOUR SAVED WIFI PASSWORDS")
    print("-----------------------------------------")
    print('\n\n')

def process():
    clrscr()
    printBanner()

    profiles = getProfiles()
    amountProfiles = profiles.count('All User Profile')

    if (amountProfiles == 0):
        print("Sorry! I can't find any WIFI saved on your PC!")

    while(amountProfiles > 0):
        wifiName = getWifiName(profiles)
        print("WIFI: {0}".format(wifiName))
        print("-->", getPassword(wifiName), end='\n\n')
        profiles = removeWifiNameInProfiles(wifiName, profiles)
        amountProfiles -= 1

def main():
    process()

if __name__ == "__main__":
    main()
