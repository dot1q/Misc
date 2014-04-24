######################
### This PowerShell script will use Ninite Pro to audit all AD computers within specified OU's
###
### $SiteArray is an array, so you may specified more than OU at a time. Use the following code to replace  the $SiteArray values:
### [Array]$SiteArray = "OU=SiteName1,OU=Sites,OU=Company", `
###                        "OU=SiteName2,OU=Sites,OU=Company"
###
###
######################

#Selects Sites to be run against
[Array]$SiteArray = "OU=Physical Machines"
					

#Source Starting location
$Source = '\\someServer\Domain_Files\ninite'

#Sets Ninite Actions
$AllArgs = @('/audit', '/remote')

#Change programs to be updated here
$Apps = @('/select', 'Flash (IE)', 'Flash', 'Java', 'Air', 'Shockwave', 'Reader')
0
#Runs the program with Arguments and generates a report
ForEach ($Site in $SiteArray) `
{
	& "$Source\NiniteOne.exe" $AllArgs ad:"$Site,DC=yourdomain,DC=local" $Apps
}


# Created by \u\stalinusmc
# Modified by dot1q
# Last updated 4/24/2014