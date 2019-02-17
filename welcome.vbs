Set Sapi = Wscript.CreateObject("SAPI.SpVoice")
Dim objShell
Set objShell = WScript.CreateObject( "WScript.Shell" )

'objShell.Run("hydron.vbs")

Sapi.speak "Hello Vishaal , I am Hydron , your virtual assistant . How can I help you ?"
