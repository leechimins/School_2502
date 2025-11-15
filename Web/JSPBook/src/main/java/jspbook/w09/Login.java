package jspbook.w09;

public class Login {
	private String id;
	private String passwd;
	
	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getPasswd() {
		return passwd;
	}

	public void setPasswd(String passwd) {
		this.passwd = passwd;
	}

	public int checkLogin() {
		if (!id.equals("김동덕")) {
			return 1;
		}
		if (!passwd.equals("1234")) {
			return -1;
		}
		return 0;
	}
}