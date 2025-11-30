package jspbook.w09;

public class UserBean {
    private String id;
    private String pw;
    private Integer gender;
    private String email;
    private String birth;

    public String getId() { return id; }
    public void setId(String id) { this.id = id; }

    public String getPw() { return pw; }
    public void setPw(String pw) { this.pw = pw; }

    public Integer getGender() { return gender; }
    public void setGender(Integer gender) { this.gender = gender; }

    public String getEmail() { return email; }
    public void setEmail(String email) { this.email = email; }

    public String getBirth() { return birth; }
    public void setBirth(String birth) { this.birth = birth; }

//    public boolean isGrownUp() {
//        String[] ymd = birth.split("-");
//        int year = Integer.parseInt(ymd[0]);
//        int currentYear = 2025;
//        int age = currentYear - year + 1;
//        return age >= 20;
//    }
//
//    public String makeStmt() {
//        String genderStr = (gender == 1) ? "여성" : "남성";
//        String adultStr = isGrownUp() ? "입니다." : "이 아닙니다.";
//        
//        return id + "씨는 " + genderStr + "이고, 성인" + adultStr;
//    }
}