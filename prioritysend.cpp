#include <znc/Client.h>
#include <znc/Modules.h>
#include <znc/IRCNetwork.h>
#include <znc/IRCSock.h>

class CPrioritySend : public CModule {
public:
	MODCONSTRUCTOR(CPrioritySend) {}
	
	virtual EModRet OnUserNotice(CString& sTarget, CString& sMessage) override {
		return ProcessMessage("NOTICE", sTarget, sMessage);
	}
	
	virtual EModRet OnUserMsg(CString& sTarget, CString& sMessage) override {
		return ProcessMessage("PRIVMSG", sTarget, sMessage);
	}
	
	EModRet ProcessMessage(const CString& sFunction, CString& sTarget, CString& sMessage) {
		if (!sMessage.TrimPrefix("(p!)")) // TODO: This could be a config variable
			return CONTINUE;
		
		CIRCSock* pIRCSock = GetNetwork()->GetIRCSock();
		
		if (!pIRCSock)
			return CONTINUE;
		
		pIRCSock->PutIRCQuick(sFunction + " " + sTarget + " :" + sMessage);
		
		return HALT;
	}
};

NETWORKMODULEDEFS(CPrioritySend, "Allows certain messages to be placed in front of the send queue")
