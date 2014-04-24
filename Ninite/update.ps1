#####################################################################################################################################
### This PowerShell script will use Ninite Pro to update all AD computers within specified OU's                                   ###
###                                                                                                                               ###
### $SiteArray is an array, so you may specified more than OU at a time. Use the following code to replace  the $SiteArray values:###
### [Array]$SiteArray = "OU=SiteName1,OU=Sites,OU=Company", `                                                                     ###
###                        "OU=SiteName2,OU=Sites,OU=Company"                                                                     ###
###                                                                                                                               ###
### You may add the '/silent' feature if you wish for the executable to run silently                                              ###
### REPORTS ARE NOT CURRENTLY AVAILIBLE!!!                                                                                        ###
#####################################################################################################################################

#Selects Sites to be run against
[Array]$SiteArray = "OU=Physical Machines"
					

#Source Starting location
$Source = '\\someServer\Domain_Files\ninite'

#Sets Ninite Actions
$AllArgs = @('/updateonly', '/disableautoupdate', '/remote')
#AllArgs will only update programs that are currently installed, will attempt to disable future auto update notifications and the /remote command
#allows us to connect to an active directory environment.

#Change programs to be updated here
$Apps = @('/select', 'Flash (IE)', 'Flash', 'Java', 'Air', 'Shockwave', 'Reader')
0
#Runs the program with Arguments
ForEach ($Site in $SiteArray) `
{
	& "$Source\NiniteOne.exe" $AllArgs ad:"$Site,DC=yourdomain,DC=local" $Apps
}

#Deletes log files that are older than 30 days
{
	$FileAge = ((Get-Date) - $File.CreationTime).Days
	If ($FileAge -gt 30 -and $File.PSIsContainer -ne $True)
		{$File.Delete()}
}


# Created by \u\stalinusmc
# Modified by dot1q
# Last updated 4/24/14