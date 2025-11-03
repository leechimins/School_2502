package ddwu.mobile.ddwu.addresstest

import android.Manifest.permission.ACCESS_COARSE_LOCATION
import android.Manifest.permission.ACCESS_FINE_LOCATION
import android.content.pm.PackageManager
import android.location.Geocoder
import android.location.Location
import android.os.Bundle
import android.os.Looper
import android.util.Log
import androidx.activity.enableEdgeToEdge
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import com.google.android.gms.location.FusedLocationProviderClient
import com.google.android.gms.location.LocationCallback
import com.google.android.gms.location.LocationRequest
import com.google.android.gms.location.LocationResult
import com.google.android.gms.location.LocationServices
import com.google.android.gms.location.Priority
import ddwu.mobile.ddwu.addresstest.databinding.ActivityMainBinding
import java.util.Locale

class MainActivity : AppCompatActivity() {
    lateinit var binding: ActivityMainBinding

    lateinit var fusedLocationClient: FusedLocationProviderClient
    lateinit var locationRequest : LocationRequest
    lateinit var locationCallback : LocationCallback

    val geocoder : Geocoder by lazy {
        Geocoder(this, Locale.getDefault())
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        checkPermissions()
        fusedLocationClient = LocationServices.getFusedLocationProviderClient(this)
        locationRequest = LocationRequest.Builder(10000)
            .setMinUpdateIntervalMillis(3000)
            .setPriority(Priority.PRIORITY_BALANCED_POWER_ACCURACY)
            .build()
        locationCallback = object : LocationCallback() {
            override fun onLocationResult(p0: LocationResult) {
                val currentLoc : Location = p0.locations[0]
                geocoder.getFromLocation(currentLoc.latitude, currentLoc.longitude, 1) {
                        addresses ->
                    Log.d("MOBILE", "${addresses.get(0).getAddressLine(0)}")
                }
            }
        }

        binding.btnOk.setOnClickListener {
            fusedLocationClient.requestLocationUpdates(
                locationRequest, locationCallback, Looper.getMainLooper()
            )
        }

        binding.btnFinish.setOnClickListener {
            fusedLocationClient.removeLocationUpdates(locationCallback)
        }
    }


    override fun onPause() {
        super.onPause()
        fusedLocationClient.removeLocationUpdates(locationCallback)
    }

    private fun checkPermissions() {
        if (checkSelfPermission(ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED
            && checkSelfPermission(ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            Log.d("MOBILE", "필요 권한 있음")
        } else {
            locationPermissionRequest.launch(
                arrayOf(ACCESS_FINE_LOCATION, ACCESS_COARSE_LOCATION)
            )
        }
    }

    val locationPermissionRequest =
        registerForActivityResult( ActivityResultContracts.RequestMultiplePermissions(), {
                permissions ->
            when {
                permissions.getOrDefault(ACCESS_FINE_LOCATION, false) -> {
                    Log.d("MOBILE", "정확한 위치 사용")
                }
                permissions.getOrDefault(ACCESS_COARSE_LOCATION, false) -> {
                    Log.d("MOBILE", "근사 위치 사용")
                }
                else -> {
                    Log.d("MOBILE", "권한 미승인")
                }
            }
        } )
}


